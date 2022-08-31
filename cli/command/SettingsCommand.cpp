#include "SettingsCommand.h"
#include "../../classifier/distance/EuclideanDistance.h"
#include "../../classifier/distance/ManhattanDistance.h"
#include "../../classifier/distance/ChebyshevDistance.h"
#include "../../classifier/Algorithms.h"

SettingsCommand::SettingsCommand(DefaultIO* dio, ClassifierData* classifierData) : Command(dio, classifierData) {
    m_description = "algorithm settings";
}

int SettingsCommand::isValidK(const std::string& str) {
    int k;

    try {
       k = std::stoi(str);
    } catch (const std::exception& e) {
        return -1;
    }

    return 0 < k && k <= 10 ? k : -1;
}

void SettingsCommand::execute() {
    m_dio->write(std::string("The current KNN parameters are:")
                + std::string(" K = ") + std::to_string(m_classifierData->classifier().k())
                + ", distance metric = " + m_classifierData->classifier().metric().name() + "\n");

    std::string input = m_dio->read();

    // If no input was given
    if (input.empty()) {
        return;
    }

    std::vector<std::string> attributes = split(input, ' ');

    // If too little arguments were given
    if (attributes.size() < 2) {
        m_dio->write("Usage: [K] [METRIC]\n");
        return;
    }

    // Validating the K value
    int k = isValidK(attributes[0]);

    if (k == -1) {
        m_dio->write("Invalid value for K\n");
        return;
    }

    // Validating the metric
    bool isValidMetric = true;

    if (attributes[1] == "EUC") {
        m_classifierData->classifier().metric(std::move(std::unique_ptr<Distance>(new EuclideanDistance())));
    } else if (attributes[1] == "CHE") {
        m_classifierData->classifier().metric(std::move(std::unique_ptr<Distance>(new ChebyshevDistance())));
    } else if (attributes[1] == "MAN") {
        m_classifierData->classifier().metric(std::move(std::unique_ptr<Distance>(new ManhattanDistance())));
    } else {
        isValidMetric = false;
    }

    if (!isValidMetric) {
        m_dio->write("Invalid metric\n");
        return;
    }

    m_classifierData->classifier().k(k);
}
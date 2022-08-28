#include "SettingsCommand.h"
SettingsCommand::SettingsCommand(DefaultIO* dio, ClassifierData* classifierData) : Command(dio, classifierData) {
    m_description = "algorithm settings";
}

void SettingsCommand::execute() {
    m_dio->write("The current KNN parameters are: K = " + std::to_string(m_classifierData->classifier().k())
                + ", distance metric = " + m_classifierData->classifier().metric().name());
    std::string inputString = m_dio->read();
    if (inputString.size() == 0) {
        return;
    }
    std::vector<std::string> splitString = split(inputString, ' ');
    auto parts = splitString.size();
    if (parts < 2) {
        if (!parts || splitString[0].size() == 0) {
            m_dio->write("Invalid input, missing values for k and for the metric!");
            return;
        }
        else if (splitString[0].size() >= 1 || splitString[0].size() <= 2) {
            char inputChar = splitString[0][0];
            if ((splitString[0].size() == 1 && inputChar <= '9' && inputChar >= '1') || (splitString[0].size() == 2 && splitString[0].compare("10"))) {
                m_dio->write("Invalid value for metric!");
            } else {
                std::string firstString = splitString[0];
                if (firstString.compare("EUC") || firstString.compare("CHE") || firstString.compare("MAN")) {
                    m_dio->write("Invalid value for K!");
                }
            }
            return;
        }
    } else if (parts >= 2) {
        std::string firstString = splitString[0];
        std::string secondString = splitString[1];
        int firstStringAsInt = std::stoi(firstString);
        if (firstStringAsInt < 0 || firstStringAsInt > 10) {
            if (!secondString.compare("EUC") && !secondString.compare("CHE") && !secondString.compare("MAN")) {
                m_dio->write("Invalid input for K and for metric!");
                return;
            }
            m_dio->write("Invalid value for K!");
        } else if (!secondString.compare("EUC") && !secondString.compare("CHE") && !secondString.compare("MAN")) {
            m_dio->write("Invalid value for metric!");
            return;
        } else {
            m_classifierData->classifier().k(firstStringAsInt);
            if (secondString.compare("EUC")) {
                std::unique_ptr<Distance> distance(new EuclideanDistance());
                m_classifierData->classifier().metric(std::move(distance));
            } else if (secondString.compare("CHE")) {
                std::unique_ptr<Distance> distance(new ChebyshevDistance());
                m_classifierData->classifier().metric(std::move(distance));
            } else {
                std::unique_ptr<Distance> distance(new ManhattanDistance());
                m_classifierData->classifier().metric(std::move(distance));
            }
        }
    }
}
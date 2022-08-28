#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    m_description = "classify data";
}

void ClassifyCommand::execute() {
    if (!m_classifierData->classifier().isInit()) {
        m_dio->write("No train file was uploaded");
        return;
    }

    if (m_classifierData->unclassifiedData().empty()) {
        m_dio->write("No test file was uploaded");
        return;
    }

    // Classify the data
    std::string res = m_classifierData->classifier().classify(m_classifierData->unclassifiedData());
    m_classifierData->classifiedData(res);

    // Inform the user the classification is done
    m_dio->write("Classifying data complete.")
}

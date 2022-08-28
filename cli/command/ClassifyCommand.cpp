#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand() {
    m_description = "classify data";
}

void ClassifyCommand::execute() {
    if (m_classifierData->unclassifiedData().empty()) {
        m_dio->write("No unclassified data was uploaded");
    }

    // Classify the data
    std::string res = m_classifierData->classifier().classify(m_classifierData->unclassifiedData());
    m_classifierData->classifiedData(res);

    //
}

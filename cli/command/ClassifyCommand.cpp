#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, ClassifierData *classifierData) : Command(dio, classifierData) {
    m_description = "classify data";
}

void ClassifyCommand::execute() {
    if (!m_classifierData->classifier().isInit()) {
        m_dio->write("No train file was uploaded\n");
        return;
    }

    if (m_classifierData->uploadedData().empty()) {
        m_dio->write("No test file was uploaded\n");
        return;
    }

    // Classify the data
    std::string res = m_classifierData->classifier().classify(m_classifierData->uploadedData());
    m_classifierData->uploadResult(res);

    // TODO: add numbers

    // Inform the user the classification is done
    m_dio->write("Classifying data complete.\n");
}

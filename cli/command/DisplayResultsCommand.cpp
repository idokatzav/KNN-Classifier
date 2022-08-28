#include "DisplayResultsCommand.h"

DisplayResultsCommand::DisplayResultsCommand(DefaultIO *dio, ClassifierData *classifierData) : Command(dio, classifierData) {
    m_description = "display results";
}

void DisplayResultsCommand::execute() {
    if (!m_classifierData->classifier().isInit()) {
        m_dio->write("Please upload first a train csv file!");
    } else {
        m_dio->write(m_classifierData->classifiedData() + "\nDone.");
    }
}
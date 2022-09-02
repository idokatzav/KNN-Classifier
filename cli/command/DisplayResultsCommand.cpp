#include "DisplayResultsCommand.h"

DisplayResultsCommand::DisplayResultsCommand(DefaultIO *dio, ClassifierData *classifierData)
        : Command(dio, classifierData) {
    m_description = "display results";
}

void DisplayResultsCommand::execute() {
    if (m_classifierData->classifiedResult().empty()) {
        m_dio->write("No classification was done\n");
        return;
    }

    //TODO: display the results

    m_dio->write(m_classifierData->classifiedResult() + "\nDone.\n");
}
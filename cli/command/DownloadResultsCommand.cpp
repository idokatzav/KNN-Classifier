#include "DownloadResultsCommand.h"

DownloadResultsCommand::DownloadResultsCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {
    m_description = "download results";
}

void DownloadResultsCommand::execute() {
    if (m_classifierData->classifiedResult().empty()) {
        m_dio->write("No classification was done\n");
        return;
    }

    // Notify the client it needs to save the content in a file
    m_dio->write("\\Download" + m_classifierData->classifiedResult() + "\\End");
}

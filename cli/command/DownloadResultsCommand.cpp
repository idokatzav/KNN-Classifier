#include "DownloadResultsCommand.h"

DownloadResultCommand::DownloadResultCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {}

void DownloadResultCommand::execute() {
    // Notify the client it needs to save the content in a file
    m_dio->write("\\Download");

    // TODO: the rest
}

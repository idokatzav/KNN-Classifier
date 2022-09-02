#include "DownloadResultsCommand.h"

DownloadResultsCommand::DownloadResultsCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {
    m_description = "download results";
}

void DownloadResultsCommand::execute() {
    // TODO: check if any classifications were done

    // Notify the client it needs to save the content in a file
    std::string res = "HELLO FROM THE OTHER SIDE"; // TODO

    m_dio->write("\\Download" + res + "\\End");
}

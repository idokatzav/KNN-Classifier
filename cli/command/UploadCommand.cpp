#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    m_description = "upload an unclassified csv data file";
}

void UploadCommand::execute() {
    // Greet the user
    m_dio->write("Please upload your local train CSV file.");

    // Receive the unclassified data from the client
    std::string data = m_dio->read();

    // Save the unclassified data
    m_classifierData->unclassifiedData(data);

    // Let the user know the unclassified data has been saved
    m_dio->write("Upload complete");
}

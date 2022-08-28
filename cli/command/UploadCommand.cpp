#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    m_description = "upload an unclassified csv data file";
}

void UploadCommand::execute() {
    // If the classifier hasn't been initialized yet
    if (!m_classifierData->classifier().isInit()) {
        // Greet the user
        m_dio->write("Please upload your local train CSV file.");

        // Receive the classified data from the client
        std::string classifiedData = m_dio->read();

        // Initialize the classifier
        m_classifierData->classifier().init(classifiedData);
    } else {
        // Greet the user
        m_dio->write("Please upload your local test CSV file.");

        // Receive the unclassified data from the client
        std::string unclassifiedData = m_dio->read();

        // Save the data
        m_classifierData->unclassifiedData(unclassifiedData);
    }

    m_dio->write("Upload complete.");
}

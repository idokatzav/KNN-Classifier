#include "UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio, ClassifierData *classifierData) : Command(dio, classifierData) {
    m_description = "upload an unclassified csv data file";
}

void UploadCommand::execute() {
    if (!m_classifierData->classifier().isInit()) {
        m_dio->write("Please upload your local train CSV file.\n");

        std::string classifiedData = m_dio->read();

        // Initialize the classifier
        m_classifierData->classifier().init(classifiedData);
    } else {
        m_dio->write("Please upload your local test CSV file.\n");

        std::string unclassifiedData = m_dio->read();

        // Save the data
        m_classifierData->uploadData(unclassifiedData);
    }

    m_dio->write("Upload complete.\n");
}

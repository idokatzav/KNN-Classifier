#ifndef KNN_CLASSIFIER_UPLOADCOMMAND_H
#define KNN_CLASSIFIER_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
    std::unique_ptr<ClassifierData> m_classifierData;

public:
    UploadCommand();

    void execute() override;
};

#endif
#ifndef KNN_CLASSIFIER_CLASSIFIYCOMMAND_H
#define KNN_CLASSIFIER_CLASSIFIYCOMMAND_H

#include "Command.h"

class ClassifyCommand : Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
    std::unique_ptr<ClassifierData> m_classifierData;

public:
    ClassifyCommand();

    void execute() override;
};


#endif
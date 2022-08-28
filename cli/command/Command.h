#ifndef KNN_CLASSIFIER_COMMAND_H
#define KNN_CLASSIFIER_COMMAND_H

#include "../io/DefaultIO.h"
#include "../../classifier/Classifier.h"
#include "../../classifierData/ClassifierData.h"
#include <string>
#include <memory>

// TODO:
// add constructor to Command
// Fix upload command
class Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
    std::unique_ptr<ClassifierData> m_classifierData;

public:
    virtual void execute() = 0;
};

#endif
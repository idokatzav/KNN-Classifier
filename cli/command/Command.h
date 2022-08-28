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
protected:
    std::string m_description;
    DefaultIO* m_dio;
    ClassifierData* m_classifierData;

public:
    Command(DefaultIO* dio, ClassifierData* classifierData);

    virtual void execute() = 0;
};

#endif
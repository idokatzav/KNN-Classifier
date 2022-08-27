#ifndef KNN_CLASSIFIER_COMMAND_H
#define KNN_CLASSIFIER_COMMAND_H

#include "../IO/DefaultIO.h"
#include "../../classifier/Classifier.h"
#include <string>
#include <memory>

class Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
    std::unique_ptr<Classifier> m_classifier;
public:
    virtual void execute() = 0;
};

#endif
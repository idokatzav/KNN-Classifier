#ifndef KNN_CLASSIFIER_COMMAND_H
#define KNN_CLASSIFIER_COMMAND_H
#include <string>
#include "DefaultIO.h"
#include <memory>

class Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
public:
    virtual void execute() = 0;
};

#endif
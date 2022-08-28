#ifndef KNN_CLASSIFIER_CLASSIFIYCOMMAND_H
#define KNN_CLASSIFIER_CLASSIFIYCOMMAND_H

#include "Command.h"

class ClassifyCommand : Command {
public:
    ClassifyCommand(DefaultIO *dio, ClassifierData *classifierData);

    void execute() override;
};


#endif
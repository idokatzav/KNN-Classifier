#ifndef KNN_CLASSIFIER_UPLOADCOMMAND_H
#define KNN_CLASSIFIER_UPLOADCOMMAND_H

#include "Command.h"

class UploadCommand : Command {
public:
    UploadCommand(DefaultIO *dio, ClassifierData *classifierData);

    void execute() override;
};

#endif
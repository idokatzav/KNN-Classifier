#ifndef KNN_CLASSIFIER_DISPLAYCONFUSIONMATRIXCOMMAND_H
#define KNN_CLASSIFIER_DISPLAYCONFUSIONMATRIXCOMMAND_H

#include "Command.h"

class DisplayConfusionMatrixCommand : public Command {
public:
    /**
     * Constructor
     * @param dio pointer to a DefaultIO object for user input and output
     * @param classifierData classifierData Object
     */
    DisplayConfusionMatrixCommand(DefaultIO* dio, ClassifierData* classifierData);

    /**
     * Execute command
     */
    void execute() override;
};
#endif
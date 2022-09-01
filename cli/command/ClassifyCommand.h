#ifndef KNN_CLASSIFIER_CLASSIFIYCOMMAND_H
#define KNN_CLASSIFIER_CLASSIFIYCOMMAND_H

#include "Command.h"

/**
 * This class represents the classify command - that classifies the data it holds.
 */
class ClassifyCommand : public Command {
public:
    /**
     * Constructor.
     * @param dio pointer to a DefaultIO object for input and output
     * @param classifierData classifierData Object
     */
    ClassifyCommand(DefaultIO *dio, ClassifierData *classifierData);

    /**
     * Execute the command.
     */
    void execute() override;
};


#endif
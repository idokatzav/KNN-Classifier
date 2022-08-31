#ifndef KNN_CLASSIFIER_UPLOADCOMMAND_H
#define KNN_CLASSIFIER_UPLOADCOMMAND_H

#include "Command.h"

/**
 * This class represents the uploadData command - that initializes the unclassified, and classified data.
 */
class UploadCommand : Command {
public:
    /**
     * Constructor.
     * @param dio pointer to a DefaultIO object for input and output
     * @param classifierData classifierData Object
     */
    UploadCommand(DefaultIO *dio, ClassifierData *classifierData);

    /**
     * Execute the command.
     */
    void execute() override;
};

#endif
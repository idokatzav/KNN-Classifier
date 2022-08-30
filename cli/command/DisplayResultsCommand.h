#ifndef KNN_CLASSIFIER_DISPLAYRESULTSCOMMAND_H
#define KNN_CLASSIFIER_DISPLAYRESULTSCOMMAND_H

#include "Command.h"

/**
 * This class represents the display results command - that displays the classifications it made.
 */
class DisplayResultsCommand : Command {
public:
    /**
     * Constructor
     * @param dio pointer to a DefaultIO object for input and output
     * @param classifierData classifierData Object
     */
    DisplayResultsCommand(DefaultIO* dio, ClassifierData* classifierData);

    /**
     * Execute command.
     */
    void execute() override;
};

#endif
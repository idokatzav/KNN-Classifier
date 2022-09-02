#ifndef KNN_CLASSIFIER_DOWNLOADRESULTSCOMMAND_H
#define KNN_CLASSIFIER_DOWNLOADRESULTSCOMMAND_H

#include "Command.h"

/**
 * This class represents the downloadResultsCommand command - downloads the results of the classification.
 */
class DownloadResultCommand : public Command {
public:
    /**
     * Constructor.
     * @param dio pointer to a DefaultIO object for userInput and output
     * @param classifierData classifierData Object
     */
    DownloadResultCommand(DefaultIO* dio, ClassifierData *classifierData);

    /**
     * Execute the command.
     */
    void execute() override;
};


#endif
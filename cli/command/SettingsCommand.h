#ifndef KNN_CLASSIFIER_SETTINGSCOMMAND_H
#define KNN_CLASSIFIER_SETTINGSCOMMAND_H

#include "Command.h"

/**
 * This class represents the settings command - that changes the classifier's parameters.
 */
class SettingsCommand : public Command {
private:
    /**
     * @param str a string representing the K value form the classifier
     * @return K if the string is a valid value, else -1
     */
    int isValidK(const std::string& str);

public:
   /**
    * Constructor.
    * @param dio pointer to a DefaultIO object for input and output
    * @param classifierData classifierData Object
    */
    SettingsCommand(DefaultIO* dio, ClassifierData* classifierData);

    /**
     * Execute the command.
     */
    void execute() override;
};
#endif
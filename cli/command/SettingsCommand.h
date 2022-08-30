#ifndef KNN_CLASSIFIER_SETTINGSCOMMAND_H
#define KNN_CLASSIFIER_SETTINGSCOMMAND_H

#include "../../classifier/distance/Distance.h"
#include "../../classifier/distance/EuclideanDistance.h"
#include "../../classifier/distance/ManhattanDistance.h"
#include "../../classifier/distance/ChebyshevDistance.h"
#include "../../classifier/Algorithms.h"
#include "Command.h"
#include <string>
#include <vector>

/**
 * This class represents the settings command - that changes the classifier's parameters.
 */
class SettingsCommand : Command {
public:
   /**
    * Constructor.
    * @param dio pointer to a DefaultIO object for input and output
    * @param classifierData classifierData Object
    */
    SettingsCommand(DefaultIO* dio, ClassifierData* classifierData);

    /**
     * @param str a string representing the K value form the calssifier
     * @return K if the string is a valid value, else -1
     */
    static int isValidK(const std::string& str);

    /**
     * Execute the command.
     */
    void execute() override;
};
#endif
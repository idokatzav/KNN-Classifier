#ifndef KNN_CLASSIFIER_SETTINGSCOMMAND_H
#define KNN_CLASSIFIER_SETTINGSCOMMAND_H
#include "Command.h"
#include <string>
#include "../../classifier/Algorithms.h"
#include <vector>
#include "../../classifier/distance/Distance.h"
#include "../../classifier/distance/EuclideanDistance.h"
#include "../../classifier/distance/ManhattanDistance.h"
#include "../../classifier/distance/ChebyshevDistance.h"
class SettingsCommand : Command {
public:
    /**
     * Constructor
     * @param dio pointer to a DefaultIO object for input and output
     * @param classifierData classifierData Object
     */
    SettingsCommand(DefaultIO* dio, ClassifierData* classifierData);
    void execute();
};
#endif
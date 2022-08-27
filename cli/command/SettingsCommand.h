#ifndef KNN_CLASSIFIER_SETTINGSCOMMAND_H
#define KNN_CLASSIFIER_SETTINGSCOMMAND_H
#include "Command.h"
#include <string>
class SettingsCommand : Command {
private:
    std::string m_description;
    std::unique_ptr<DefaultIO> m_dio;
    std::unique_ptr<ClassifierData> m_classifierData;

public:
    void execute();
};
#endif
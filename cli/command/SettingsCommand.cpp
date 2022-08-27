#include "SettingsCommand.h"
void SettingsCommand::execute() {
    m_dio->write("The current KNN parameters are: K = " + std::to_string(m_classifierData->classifier().k())
                + ", distance metric = " + m_classifierData->getMetric());
}
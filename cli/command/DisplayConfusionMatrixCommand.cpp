#include "DisplayConfusionMatrixCommand.h"

DisplayConfusionMatrixCommand::DisplayConfusionMatrixCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {
    m_description = "display algorithm confusion matrix";
}

void DisplayConfusionMatrixCommand::execute() {
    if (m_classifierData->classifiedResult().empty()) {
        m_dio->write("No classification was done\n");
        return;
    }

    m_dio->write(m_classifierData->classifier().confusionMatrixString());
}

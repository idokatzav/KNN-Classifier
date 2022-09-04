#include "DisplayConfusionMatrixCommand.h"

DisplayConfusionMatrixCommand::DisplayConfusionMatrixCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {
    m_description = "display algorithm confusion matrix";
}

void DisplayConfusionMatrixCommand::execute() {
    if (!m_classifierData->classifier().isInit()) {
        m_dio->write("No train file was uploaded\n");
        return;
    }

    m_dio->write(m_classifierData->classifier().confusionMatrixString());
}

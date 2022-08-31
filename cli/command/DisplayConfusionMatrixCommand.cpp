#include "DisplayConfusionMatrixCommand.h"

DisplayConfusionMatrixCommand::DisplayConfusionMatrixCommand(DefaultIO *dio, ClassifierData *classifierData) :
    Command(dio, classifierData) {
    m_description = "display algorithm confusion matrix";
}

void DisplayConfusionMatrixCommand::execute() {
    // TODO: add confusion matrix function in classifier

    /*if (m_classifierData->classifiedResult().empty()) {
        m_dio->write("No classification was done\n");
        return;
    }

    std::vector<std::string> trainResults;
    std::vector<std::unique_ptr<Classified>>& classified = m_classifierData->classifier().ClassifiedDataVector();
    auto len = classified.size();

    for (int i = 0; i < len; ++i) {
        std::string str = "";
        std::vector<double> vec;
        std::vector<double> givenVec = classified[i]->data();
        auto len1 = givenVec.size();
        for (int j = 0; j < len1; ++j) {
            vec.push_back(givenVec[j]);
        }
        Classified toClassifiy(str, vec);
        m_classifierData->classifier().classify(toClassifiy);
        trainResults.push_back(toClassifiy.handle());
    }*/
}

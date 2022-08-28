#ifndef KNN_CLASSIFIER_CLI_H
#define KNN_CLASSIFIER_CLI_H

#include "command/Command.h"
#include "io/DefaultIO.h"
#include <memory>

class Cli {
private:
    std::unique_ptr<DefaultIO> m_dio;
public:
    void start();
};


#endif

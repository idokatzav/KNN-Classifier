#ifndef KNN_CLASSIFIER_CLI_H
#define KNN_CLASSIFIER_CLI_H

#include "command/Command.h"
#include "io/DefaultIO.h"
#include "../classifierData/ClassifierData.h"
#include <memory>

class Cli {
private:
    DefaultIO* m_dio;
    ClassifierData* m_classifierData;
    std::vector<Command*> m_commands;

public:
    /**
     * Constructor.
     * @param dio the default IO the commands will use
     */
    Cli(DefaultIO* dio);

    /**
     * Start the cli.
     */
    void start();

    /**
     * Destructor.
     */
     ~Cli();
};


#endif

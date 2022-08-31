#ifndef KNN_CLASSIFIER_CLI_H
#define KNN_CLASSIFIER_CLI_H

#include "command/Command.h"
#include "io/DefaultIO.h"
#include <memory>

class Cli {
private:
    std::unique_ptr<DefaultIO> m_dio;
    std::vector<Command*>& m_commands;

public:
    /**
     * Constructor.
     */
    Cli(DefaultIO* dio, std::vector<Command*>& commands);

    /**
     * Start the cli.
     */
    void start();
};


#endif

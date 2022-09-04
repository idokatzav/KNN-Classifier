#ifndef KNN_CLASSIFIER_STANDARDIO_H
#define KNN_CLASSIFIER_STANDARDIO_H

#include "DefaultIO.h"

/**
 * This class represents communication via the standard io.
 */
class StandardIO : public DefaultIO {
public:
    /**
     * Reads user input and returns it as a string.
     * @return the user input
     */
    std::string read() override;

    /**
     * Writes the given output.
     * @param str the output
     */
    void write(const std::string &str) override;
};

#endif

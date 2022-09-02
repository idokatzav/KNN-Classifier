#ifndef KNN_CLASSIFIER_DEFAULTIO_H
#define KNN_CLASSIFIER_DEFAULTIO_H

#include <string>

/**
 * This class represents a form of communication.
 */
class DefaultIO {
public:
    /**
     * Reads userInput and returns it as a string.
     * @return the userInput
     */
    virtual std::string read() = 0;

    /**
     * Writes the given output.
     * @param str the output
     */
    virtual void write(const std::string &str) = 0;

    /**
     * Destructor.
     */
     virtual ~DefaultIO() = default;
};

#endif
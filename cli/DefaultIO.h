#ifndef KNN_CLASSIFIER_DEFAULTIO_H
#define KNN_CLASSIFIER_DEFAULTIO_H

class DefaultIO {
public:
    /**
     * reads input and returns it as a string
     * @return the input
     */
    virtual std::string read() = 0;
    /**
     * writes the given output
     * @param str the output
     */
    virtual void write(std::string str) = 0;
};
#endif
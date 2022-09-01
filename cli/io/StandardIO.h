#ifndef KNN_CLASSIFIER_STANDARDIO_H
#define KNN_CLASSIFIER_STANDARDIO_H

#include "DefaultIO.h"

class StandardIO : public DefaultIO {
public:
    std::string read() override;

    void write(const std::string &str) override;
};

#endif

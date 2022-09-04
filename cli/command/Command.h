#ifndef KNN_CLASSIFIER_COMMAND_H
#define KNN_CLASSIFIER_COMMAND_H

#include "../../classifierData/ClassifierData.h"
#include "../io/DefaultIO.h"

/**
 * This class represents an abstract command.
 */
class Command {
protected:
    ClassifierData* m_classifierData;
    std::string m_description;
    DefaultIO* m_dio;

public:
    /**
     * Constructor.
     * @param dio pointer to a DefaultIO object for user input and output
     * @param classifierData classifierData Object
     */
    Command(DefaultIO* dio, ClassifierData* classifierData);

    /**
     * @return the command's description
     */
    std::string description() const;

    /**
     * Execute the command.
     */
    virtual void execute() = 0;

    /**
     * Destructor.
     */
     virtual ~Command() = default;
};

#endif
#ifndef KNN_CLASSIFIER_CLASSIFIERDATA_H
#define KNN_CLASSIFIER_CLASSIFIERDATA_H

#include "../classifier/Classifier.h"
#include <memory>

/**
 * This class holds all the information needed by the server when communicating with the client.
 */
class ClassifierData {
private:
    std::unique_ptr<Classifier> m_classifier;
    std::string m_uploadedData;
    std::string m_classifiedResult;
public:
    /**
     * Constructor.
     */
    ClassifierData();

    /**
     * Classifier getter.
     * @return the classifier
     */
    Classifier& classifier() const;

    /**
     * UnclassifiedData getter.
     * @return the unclassified data
     */
    std::string unclassifiedData() const;

    /**
     * UnclassifiedData setter.
     */
    void unclassifiedData(const std::string& unclassifiedData);

    /**
     * ClassifiedData getter.
     * @return the classified data
     */
    std::string classifiedData() const;

    /**
     * ClassifiedData setter.
     * @param classifiedData the classified data
     */
   void classifiedData(const std::string& classifiedData);
};

#endif
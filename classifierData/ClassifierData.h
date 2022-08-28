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
    std::string m_unclassifiedData;
    std::string m_classifiedData;
public:
    /**
     * Constructor.
     * @param classifier a classifier
     */
    ClassifierData(std::unique_ptr<Classifier> classifier);

    /**
     * Classifier getter.
     * @return the classifier
     */
    Classifier& classifier() const;

    /**
     * unclassifiedData getter.
     * @return the unclassified data
     */
    std::string unclassifiedData() const;

    /**
     * unclassifiedData setter.
     */
    void unclassifiedData(const std::string& unclassifiedData);

    /**
     * classifiedData getter.
     * @return the classified data
     */
    std::string classifiedData() const;

    /**
     * classifiedData setter.
     * @param classifiedData the classified data
     */
   void classifiedData(const std::string& classifiedData);
};

#endif
#ifndef KNN_CLASSIFIER_CLASSIFIERDATA_H
#define KNN_CLASSIFIER_CLASSIFIERDATA_H

#include "../classifier/Classifier.h"
#include <memory>

/**
 * This class holds all the information needed by the server when communicating with the client.
 */
class ClassifierData {
private:
    Classifier* m_classifier;
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
     * UploadedData getter.
     * @return the uploaded data
     */
    std::string uploadedData() const;

    /**
     * UploadedData setter.
     */
    void uploadData(const std::string& uploadedData);

    /**
     * ClassifiedData getter.
     * @return the classified data
     */
    std::string classifiedResult() const;

    /**
     * ClassifiedResult setter.
     * @param classifiedData the classified result
     */
   void uploadResult(const std::string& classifiedResult);

   /**
    * Destructor.
    */
   ~ClassifierData();
};

#endif
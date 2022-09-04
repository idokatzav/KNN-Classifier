#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "distance/Distance.h"
#include "Classified.h"
#include <string>
#include <memory>
#include <map>
#include <cmath>

/**
 * This class represents a classifier, possible of classifying points in a dataset.
 */
class Classifier {
private:
    int m_k;
    bool m_isInit;
    std::unique_ptr<Distance> m_metric;
    std::vector<std::unique_ptr<Classified>> m_classifiedData;
    std::unique_ptr<std::map<std::string, int>> m_handles;
    std::string m_confusionMatrixStr;

    /**
    * creates a string contains the confusion matrix
    * @return the string wih the information.
    */
    std::string confusionMatrix();

public:
    /**
     * Constructor.
     */
    Classifier();

    /**
     * Initialize the classified data the KNN algorithm will utilise.
     * @param classifiedData the classified data
     */
    void init(const std::string& classifiedData);

    /**
     * @return whether the classifier has been initialized yet
     */
    bool isInit() const;

    /**
     * K getter.
     * @return k
     */
    int k() const;

    /**
     * K setter.
     * @param k the new integer to be used in the KNN algorithm
     */
    void k(int k);

    /**
     * Metric getter.
     * @return the metric used in the KNN algorithm
     */
    Distance& metric() const;

    /**
     * Metric setter.
     * @param metric the new metric to be used in the KNN algorithm
     */
    void metric(std::unique_ptr<Distance> metric);

    /**
     * Given unclassified data and a distance metric, this method uses
     * the KNN algorithm to classify the object
     * @param unclassified an unclassified object
     * @param distance a distance metric
     */
    void classify(Classified& unclassified) const;

    /**
     * Given unclassified data in a csv format, this method uses
     * the KNN algorithm to classify the object
     * @param unclassifiedData unclassified data, in a csv format
     * @param distance a distance metric
     * @return a string in a csv format with the classified data
     */
    std::string classify(const std::string& unclassifiedData) const;

    /**
     * Getter for the confusion matrix
     * @return the string
     */
    std::string confusionMatrixString() const;

};

#endif
#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "Classified.h"
#include "distance/Distance.h"
#include <string>
#include <memory>

class Classifier {
private:
    int m_k;
    bool m_isInit;
    std::vector<std::unique_ptr<Classified>> m_classifiedData;
    std::unique_ptr<Distance> m_metric;

public:
    /**
     * Constructor.
     * @param k the parameter used in the KNN algorithm
     * @param the metric used in the KNN algorithm
     */
    Classifier(int k, std::unique_ptr<Distance> metric);

    /**
     * Initialize the classified data the KNN algorithm will utilise, from a CSV file.
     * @param dataPath the path to the classified data
     */
    void initFromFile(const std::string& dataPath);

    /**
     * k setter.
     * @param k the new integer to be used in the KNN algorithm.
     */
    void k(int k);

    /**
     * metric setter.
     * @param k the new metric to be used in the KNN algorithm.
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
     * getter for k
     * @return k
     */
    int k();
};

#endif
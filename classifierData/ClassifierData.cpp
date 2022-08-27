#include "ClassifierData.h"

ClassifierData::ClassifierData(std::unique_ptr<Classifier> classifier) {
    m_classifier = std::move(classifier);
}

void ClassifierData::metric(std::unique_ptr<Distance> metric) {
    m_metric = std::move(metric);
}

Classifier& ClassifierData::classifier() const {
    return *m_classifier;
}

std::string ClassifierData::unclassifiedData() const {
    return m_unclassifiedData;
}

Distance& ClassifierData::metric() {
    return *m_metric;
}

void ClassifierData::unclassifiedData(const std::string& unclassifiedData) {
    m_unclassifiedData = unclassifiedData;
}

std::string ClassifierData::classifiedData() const {
    return m_classifiedData;
}

void ClassifierData::classifiedData(const std::string& classifiedData) {
    m_classifiedData = classifiedData;
}

std::string ClassifierData::getMetric() {
    return m_metric->metricString();
}
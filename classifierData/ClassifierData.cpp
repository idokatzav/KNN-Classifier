#include "ClassifierData.h"

ClassifierData::ClassifierData(std::unique_ptr<Classifier> classifier) {
    m_classifier = std::move(classifier);
}

Classifier& ClassifierData::classifier() const {
    return *m_classifier;
}

std::string ClassifierData::unclassifiedData() const {
    return m_unclassifiedData;
}

void ClassifierData::unclassifiedData(const std::string &unclassifiedData) {
    m_unclassifiedData = unclassifiedData;
}

std::string ClassifierData::classifiedData() const {
    return m_classifiedData;
}

void ClassifierData::classifiedData(const std::string& classifiedData) {
    m_classifiedData = classifiedData;
}

#include "ClassifierData.h"

ClassifierData::ClassifierData() {
    m_classifier = std::unique_ptr<Classifier>(new Classifier());
}

Classifier& ClassifierData::classifier() const {
    return *m_classifier;
}

std::string ClassifierData::unclassifiedData() const {
    return m_unclassifiedData;
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
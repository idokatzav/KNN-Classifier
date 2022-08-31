#include "ClassifierData.h"

ClassifierData::ClassifierData() {
    m_classifier = new Classifier();
}

Classifier& ClassifierData::classifier() const {
    return *m_classifier;
}

std::string ClassifierData::uploadedData() const {
    return m_uploadedData;
}

void ClassifierData::uploadData(const std::string& unclassifiedData) {
    m_uploadedData = unclassifiedData;
}

std::string ClassifierData::classifiedResult() const {
    return m_classifiedResult;
}

void ClassifierData::uploadResult(const std::string& classifiedData) {
    m_classifiedResult = classifiedData;
}

ClassifierData::~ClassifierData() {
    delete m_classifier;
}

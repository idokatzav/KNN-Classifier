#include "Classifier.h"
#include "distance/EuclideanDistance.h"
#include "Algorithms.h"
#include <fstream>
#include <sstream>

Classifier::Classifier() : m_isInit(false) {
    // Initialize the classified with default values
    m_k = 5;
    m_metric =  std::unique_ptr<Distance>(new EuclideanDistance());
}

void Classifier::init(const std::string& classifiedData) {
    std::istringstream f(classifiedData);
    std::string line;

    // Iterate through the csv file, and gather the classified objects' data and classifications
    while (std::getline(f, line)) {
        m_classifiedData.push_back(Classified::fromLine(line));
    }

    m_isInit = true;
}

bool Classifier::isInit() const {
    return m_isInit;
}

int Classifier::k() const {
    return m_k;
}

void Classifier::k(int k) {
    m_k = k;
}

Distance& Classifier::metric() const {
    return *m_metric;
}

void Classifier::metric(std::unique_ptr<Distance> metric) {
    m_metric = std::move(metric);
}

void Classifier::classify(Classified& unclassified) const {
    if (!m_isInit) {
        throw std::runtime_error("Classifier uninitialized");
    }

    // Measure the distances from the unclassified data to the points in the dataset
    std::vector<double> distances;
    auto dataSize = m_classifiedData.size();

    for (int i = 0; i < dataSize; ++i) {
        try {
            distances.push_back(m_metric->distance(unclassified.data(), m_classifiedData[i]->data()));
        } catch (const std::invalid_argument& ia) {
            unclassified.handle("");
            return;
        }
    }

    // Find the K nearest neighbours, and the most common handle among them
    std::map<std::string, int> map;
    std::vector<int> indices = kSmallestElements(distances, m_k);

    for (int i = 0; i < m_k; ++i) {
        std::string handle = m_classifiedData[indices[i]]->handle();

        if (map.find(handle) == map.end()) {
            map[handle] = 1;
        } else {
            map[handle]++;
        }
    }

    // Give the unclassified object the correct handle
    unclassified.handle(maxKey(map));
}

std::string Classifier::classify(const std::string& unclassifiedData) const {
    std::vector<std::string> lines = split(unclassifiedData, '\n');
    std::string res;

    for (auto & line : lines) {
        std::unique_ptr<Classified> unclassified = Classified::fromLine(line);
        classify(*unclassified);
        res += unclassified->handle() + "\n";
    }

    return res;
}

std::vector<std::unique_ptr<Classified>>& Classifier::ClassifiedDataVector() {
    return m_classifiedData;
}
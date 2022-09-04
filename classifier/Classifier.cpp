#include "distance/EuclideanDistance.h"
#include "Classifier.h"
#include "Algorithms.h"
#include <fstream>
#include <sstream>

Classifier::Classifier() : m_isInit(false) {
    // Initialize the classified with default values
    m_k = 5;
    m_metric =  std::unique_ptr<Distance>(new EuclideanDistance());
    m_handles = std::unique_ptr<std::map<std::string, int>>(new std::map<std::string, int>);
    m_confusionMatrixStr = "";
}

void Classifier::init(const std::string& classifiedData) {
    if (m_isInit) {
        throw std::runtime_error("Classifier already initialized");
    }

    std::istringstream f(classifiedData);
    std::string line;

    // Iterate through the csv file, and gather the classified objects' data and classifications
    while (std::getline(f, line)) {
        std::unique_ptr<Classified> classified = Classified::fromLine(line);
        std::string handle = classified->handle();

        if (m_handles->count(handle)) {
            m_handles->at(handle)++;
        } else {
            m_handles->operator[](handle) = 1;
        }

        m_classifiedData.push_back(std::move(classified));
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

    // Find the K nearest neighbours, and the most common handles among them
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

    // Give the unclassified object the correct handles
    unclassified.handle(maxKey(map));
}

std::string Classifier::classify(const std::string& unclassifiedData) const {
    std::vector<std::string> lines = split(unclassifiedData, '\n');
    int size = lines.size();
    std::string res;

    for (int i = 0; i < size; ++i) {
        std::unique_ptr<Classified> unclassified = Classified::fromLine(lines[i]);
        classify(*unclassified);
        res +=  std::to_string(i + 1) + ". " + unclassified->handle();

        if (i < size - 1) {
            res += "\n";
        }
    }

    return res;
}

std::string Classifier::confusionMatrix() {
    if (!isInit()) {
        throw std::runtime_error("Classifier uninitialized");
    }

    std::string res = "\t";

    // Create the first row of the
    for (const std::pair<const std::string, int>& pair : *(m_handles)) {
        res += pair.first + "\t";
    }

    res += "\n";

    // Iterate through all the handles and their occurrences in the saved classified data
    for (const std::pair<const std::string, int>& pair : *(m_handles)) {
        // Add the row handle specifier
        res += pair.first + "\t";

        /*
         * For each classified vector, of the same handle as the iterated one,
         * classify it again, and save the classified result, as well as the number of times it appeared.
         */
        std::map<std::string, int> curTypeMap;

        for (auto& classified : m_classifiedData) {
            if (classified->handle() == pair.first) {
                std::vector<double> attributes = classified->data();

                // Classify the classified data
                Classified curClassified("", attributes);
                classify(curClassified);
                std::string handle = curClassified.handle();

                if (curTypeMap.count(handle)) {
                    curTypeMap.at(handle)++;
                } else {
                    curTypeMap[handle] = 1;
                }
            }
        }

        int numberOfOccurrences = pair.second;

        // Iterate through the handles and construct the row matching the handle
        for (const std::pair<const std::string, int>& handle : *(m_handles)) {
            int percentage = 0;

            if (curTypeMap.count(handle.first)) {
                int ratio = 100 * curTypeMap[handle.first] / numberOfOccurrences;
                double preciseRatio = (double) 100 * curTypeMap[handle.first] / numberOfOccurrences;

                int roundIndicator = (preciseRatio - ratio >= 0.5) ? 1 : 0;
                percentage += ratio + roundIndicator;
            }

            res += std::to_string(percentage) + "%\t";
        }

        res += "\n";
    }

    m_confusionMatrixStr = res;
}

std::string Classifier::confusionMatrixString() {
    // Create the confusion matrix
    confusionMatrix();

    return m_confusionMatrixStr;
}
#include "Classified.h"
#include "Algorithms.h"
#include <stdexcept>

Classified::Classified() {
    m_handle = "";
}

Classified::Classified(std::string handle, std::vector<double>& data) {
    m_handle = std::move(handle);
    m_data = data;
}

Classified::Classified(const Classified& classified) {
    m_handle = classified.m_handle;
    m_data = classified.data();
}

const std::string& Classified::handle() const {
    return m_handle;
}

const std::vector<double>& Classified::data() const {
    return m_data;
}

void Classified::handle(std::string handle) {
    m_handle = std::move(handle);
}

std::unique_ptr<Classified> Classified::fromLine(const std::string& line) {
    std::vector<std::string> attributes = split(line, ',');
    auto size = attributes.size();

    std::string handle = attributes[size - 1];
    std::vector<double> vData;

    // If no handles was given, the entire line is consisted of numerical data
    if (isDouble(handle)) {
        size++;
        handle = "";
    }

    for (int i = 0; i < size - 1; ++i) {
        try {
            vData.push_back(std::stod(attributes[i]));
        } catch (const std::invalid_argument& ia) {
            // If the line is corrupt
            handle = "";
            vData.clear();
            break;
        }
    }

    std::unique_ptr<Classified> uniquePtr(new Classified(handle, vData));
    return std::move(uniquePtr);
}



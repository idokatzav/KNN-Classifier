#include "EuclideanDistance.h"
#include "../Algorithms.h"

double EuclideanDistance::distance(const std::vector<double>& v1, const std::vector<double>& v2) const {
    return len(v1 - v2);
}

std::string EuclideanDistance::name() {
    return "EUC";
}
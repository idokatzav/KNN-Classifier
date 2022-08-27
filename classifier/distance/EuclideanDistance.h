#ifndef EUCLIDEANDISTANCE_H
#define EUCLIDEANDISTANCE_H

#include "Distance.h"

class EuclideanDistance : public Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the euclidean distance between the two
     */
    double distance(const std::vector<double>& v1, const std::vector<double>& v2) const override;

    /**
      * get a string of the name of the metric.
      * @return string form of the metric
      */
    std::string metricString() override;
};

#endif

#ifndef CHEBYSHEVDISTANCE_H
#define CHEBYSHEVDISTANCE_H

#include "Distance.h"

class ChebyshevDistance : public Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the chebyshev distance between the two
     */
    double distance(const std::vector<double>& v1, const std::vector<double>& v2) const override;

    /**
      * get a string of the name of the metric.
      * @return string form of the metric
      */
    std::string metricString() override;
};

#endif

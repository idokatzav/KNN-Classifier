#ifndef CHEBYSHEVDISTANCE_H
#define CHEBYSHEVDISTANCE_H

#include "Distance.h"

/**
 * This class represents the Chebyshev metric.
 */
class ChebyshevDistance : public Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the chebyshev distance between the two
     */
    double distance(const std::vector<double>& v1, const std::vector<double>& v2) const override;

    /**
     * @return the name of the metric
     */
    std::string name() const override;
};

#endif

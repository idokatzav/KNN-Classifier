#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "Distance.h"

/**
 * This class represents the Manhattan metric.
 */
class ManhattanDistance : public Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the manhattan distance between the two
     */
    double distance(const std::vector<double>& v1, const std::vector<double>& v2) const override;

    /**
     * @return the name of the metric
     */
    std::string name() const override;
};

#endif

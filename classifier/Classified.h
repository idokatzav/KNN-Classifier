#ifndef Classified_H
#define Classified_H

#include <vector>
#include <string>
#include <memory>

/**
 * This class represents a point in a dataset.
 */
class Classified {
private:
    std::vector<double> m_data;
    std::string m_handle;

public:
    /**
     * Constructor.
     */
    Classified();

    /**
     * Constructor.
     * @param handle the classification of the object
     * @param data the data
     */
    Classified(std::string handle, std::vector<double>& data);

    /**
    * Copy constructor.
    * @param classified another classified instance
    */
    Classified(const Classified& classified);

    /**
     * Handle getter.
     */
    const std::string& handle() const;

    /**
     * Data getter.
     */
    const std::vector<double>& data() const;

    /**
     * Handle setter
     */
    void handle(std::string handle);

    /**
     * Given a Classified object represented in a CSV format, return a pointer to the object.
     * @param line the classified object in a CSV format
     * @return the classified object
     */
    static std::unique_ptr<Classified> fromLine(const std::string& line);
};

#endif

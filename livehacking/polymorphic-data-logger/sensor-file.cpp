#include "sensor-file.h"

#include <stdexcept>
#include <fstream>
#include <string>

double FileSensor::get_value() const
{
    std::ifstream f(_filename);
    if (!f.is_open()) {
        std::string msg = "Cannot open " + _filename;
        throw std::runtime_error(msg);
    }

    double value;
    f >> value;
    return value;
}

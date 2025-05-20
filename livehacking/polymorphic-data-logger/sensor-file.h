#pragma once

#include "sensor.h"
#include <string>

class FileSensor : public Sensor
{
public:
    FileSensor(const std::string& filename) : _filename{filename} {}
    double get_value() const override;            // <-- dogmatic

private:
    std::string _filename;
};

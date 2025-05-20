#pragma once

#include "sensor.h"
#include <chrono>
#include <iostream>

class Logger
{
public:
    Logger(Sensor* sensor) : _sensor(sensor) {}
    void log_one()
    {
        auto now = std::chrono::system_clock::now();
        double value = _sensor->get_value();
        std::cout << "time: " << now << ", value: " << value << std::endl;
    }
private:
    Sensor* _sensor;
};


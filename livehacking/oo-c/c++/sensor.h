#pragma once

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual double get_value() = 0;
};

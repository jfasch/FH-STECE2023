#pragma once

class Analog_Sensor
{
public:
    virtual ~Analog_Sensor() = default;
    
    virtual float get_value() const = 0;
    virtual float set_value() const = 0;
};
#pragma once

class AnalogSensor
{
public:
    virtual ~AnalogSensor() = default;
    
    virtual float get_value() const = 0;
    virtual float set_value() const = 0;
};
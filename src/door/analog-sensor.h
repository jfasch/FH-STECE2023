#pragma once

class AnalogSensor
{
public:
    virtual ~AnalogSensor() = default;

    virtual float get_value() const = 0;
    virtual void set_value(float value) const = 0;
};

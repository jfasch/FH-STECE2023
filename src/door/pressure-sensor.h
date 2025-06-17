#pragma once

class PressureSensor
{
public:
    virtual ~PressureSensor() = default;
    virtual float get_pressure() const = 0;

    //for tests only
    virtual void set_pressure(float pressure) = 0;
};
#pragma once

class PressureSensor
{
public:
    virtual ~PressureSensor() = default;
    virtual float get_pressure() const = 0;
};
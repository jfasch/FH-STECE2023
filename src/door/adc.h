#pragma once

class Adc
{
public:
    virtual ~Adc() = default;
    virtual float get_value() const = 0;
};
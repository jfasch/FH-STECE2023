#pragma once
#include "adc.h"

class MockAdc : public Adc
{
public:
    MockAdc();
    float get_value() const override;
    // for tests
    void set_value(float value);
private:
    float _value;
};
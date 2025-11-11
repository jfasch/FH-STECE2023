#pragma once
#include "analog-sensor.h"

class MockAnalogSensor : public AnalogSensor
{
public:
MockAnalogSensor();
    float get_value() const override;
    // for tests
    void set_value(float value);
private:
    float _value;
};
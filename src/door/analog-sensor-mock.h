#pragma once
#include "analog-sensor.h"

class MockAnalog_Sensor : public Analog_Sensor
{
public:
MockAnalog_Sensor();
    float get_value() const override;
    // for tests
    void set_value(float value);
private:
    float _value;
};
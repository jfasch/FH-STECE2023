#pragma once

#include "sensor.h"

class MockSensor : public Sensor
{
public:
    MockSensor(double initial_value) : _value{initial_value} {}
    double get_value() const override   // <-- dogmatic
    { return _value; }
private:
    double _value;
};

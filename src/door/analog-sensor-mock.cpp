#include "analog-sensor-mock.h"

MockAnalogSensor::MockAnalogSensor() : _value {}{}

float MockAnalogSensor::get_value() const
{
    return _value;
}

void MockAnalogSensor::set_value(float value)
{
    _value = value;
}

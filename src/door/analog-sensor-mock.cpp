#include "analog-sensor-mock.h"

MockAnalog_Sensor::MockAnalog_Sensor() : _value {}{}

float MockAnalog_Sensor::get_value() const
{
    return _value;
}

void MockAnalog_Sensor::set_value(float value)
{
    _value = value;
}

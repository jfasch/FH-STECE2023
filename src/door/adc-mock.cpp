#include "adc-mock.h"

MockAdc::MockAdc() : _value {}{}

float MockAdc::get_value() const
{
    return _value;
}

void MockAdc::set_value(float value)
{
    _value = value;
}

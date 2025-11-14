#include "pressure-sensor-mock.h"

PressureSensorMock::PressureSensorMock(float pressure)
: _pressure { pressure } {}

float PressureSensorMock::get_pressure() const
{
    return _pressure;
}

void PressureSensorMock::set_pressure(float pressure)
{
    _pressure = pressure;
}
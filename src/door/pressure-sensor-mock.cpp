#include "pressure-sensor-mock.h"

PressureSensorMock::PressureSensorMock()
: _pressure {}{}

float PressureSensorMock::get_pressure() const
{
    return _pressure;
}

void PressureSensorMock::set_pressure(float pressure)
{
    _pressure = pressure;
}
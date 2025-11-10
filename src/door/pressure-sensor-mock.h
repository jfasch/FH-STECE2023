#pragma once

#include "pressure-sensor.h"

class PressureSensorMock : public PressureSensor
{
public:
    PressureSensorMock(float pressure = 0.0f);
    float get_pressure() const override;

    //for tests
    void set_pressure(float pressure);

private:
    float _pressure;
};
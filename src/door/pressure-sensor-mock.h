#pragma once

#include "pressure-sensor.h"

class PressureSensorMock : public PressureSensor
{
public:
    PressureSensorMock(float pressure);
    float get_pressure() const override;

    //for tests
    void set_pressure(float pressure) override;

private:
    float _pressure;
};
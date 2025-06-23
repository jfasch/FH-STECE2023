#pragma once

#include "pressure-sensor.h"

class PressureSensorMock : public PressureSensor
{
public:
    PressureSensorMock();
    float get_pressure() const override;

    //for tests
    void set_pressure(float pressure);

private:
    float _pressure;
};
#pragma once

#include "pressure-sensor.h"

class BMP280 : public PressureSensor
{
public:
    BMP280(const std::string& i2c_device = "/dev/i2c-1");
    
    float get_pressure() const override;

    //for tests
    void set_pressure(float pressure) override;

private:
    float _pressure;
};
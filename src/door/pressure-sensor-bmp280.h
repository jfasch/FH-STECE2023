#pragma once

#include "pressure-sensor.h"

class BMP280 : public PressureSensor
{
public:
    BMP280(const std::string& i2c_device = "/dev/i2c-1", unsigned address = 0x76);
    ~BMP280();
    
    float get_pressure() const;

    void set_pressure(float pressure) override;

private:
    int _fd;
};

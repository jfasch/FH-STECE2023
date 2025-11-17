#pragma once

#include <cstdint>
#include <string>

#include "analog-sensor.h"

class BMP280 : public AnalogSensor
{
public:
    BMP280(const std::string& i2c_device = "/dev/i2c-1", unsigned address = 0x76);
    ~BMP280();

    float get_value() const override;

private:
    int _fd;
    uint16_t _dig_T1;
    int16_t  _dig_T2;
    int16_t  _dig_T3;
    uint16_t _dig_P1;
    int16_t  _dig_P2;
    int16_t  _dig_P3;
    int16_t  _dig_P4;
    int16_t  _dig_P5;
    int16_t  _dig_P6;
    int16_t  _dig_P7;
    int16_t  _dig_P8;
    int16_t  _dig_P9;
};

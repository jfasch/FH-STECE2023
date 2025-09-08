#pragma once

#include "adc.h"
#include <string>
#include <cstdint>

class Ads1115 : public Adc
{
public:
    Ads1115(const std::string& device_path, uint8_t i2c_address);

    ~Ads1115() override;

    float get_value() const override;

private:
    int file_descriptor_ = -1;
    float voltage_multiplier_;
};

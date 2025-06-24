#pragma once

#include "light-barrier.h"
#include <gpiod.h>
#include <string>

class LightBarrierGPIO : public LightBarrier {
public:
    LightBarrierGPIO(const std::string& gpiodevice, unsigned int* line_number);
    ~LightBarrierGPIO();

    State get_state();

private:
    std::string _gpiodevice;
    unsigned int* _line_number;
    gpiod_chip* _chip;

    gpiod_line_request* request;
    gpiod_line_settings* settings;
    gpiod_line_config* line_cfg;
};
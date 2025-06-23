#pragma once

#include "light-barrier.h"
#include <gpiod.hpp>
#include <string>

class LightBarrierGPIO : public LightBarrier {
public:
    LightBarrierGPIO(const std::string& gpiodevice, int line_number);
    ~LightBarrierGPIO();

    State get_state() override;

private:
    std::string _gpiodevice;
    int _line_number;

    gpiod::chip _chip;
    gpiod::line_request _request;
};
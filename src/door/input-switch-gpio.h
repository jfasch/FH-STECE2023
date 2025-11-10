#pragma once

#include "input-switch.h"
#include <gpiod.h>
#include <string>

class InputSwitchGPIO : public InputSwitch {
public:
    InputSwitchGPIO(const std::string& gpiodevice, unsigned int line_number);
    ~InputSwitchGPIO();

    State get_state();

    // Prevent copying
    InputSwitchGPIO(const InputSwitchGPIO&) = delete;
    InputSwitchGPIO& operator=(const InputSwitchGPIO&) = delete;

private:
    std::string _gpiodevice;
    unsigned int _line_number;
    gpiod_chip* _chip;

    gpiod_line_request* request;
    gpiod_line_settings* settings;
    gpiod_line_config* line_cfg;
};

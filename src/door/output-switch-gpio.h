#pragma once

#include "output-switch.h"
#include <gpiod.h>
#include <string>

class OutputSwitchGPIO : public OutputSwitch {
public:
    OutputSwitchGPIO(const std::string& gpiodevice, unsigned int line_number);
    ~OutputSwitchGPIO();

    void set_state(State state) override;

private:
    std::string _gpiodevice;
    unsigned int _line_number;
    gpiod_chip* _chip;

    gpiod_line_request* request;
    gpiod_line_settings* settings;
    gpiod_line_config* line_cfg;
};
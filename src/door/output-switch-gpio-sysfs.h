#pragma once

#include "output-switch.h"
#include <string>

class OutputSwitchGPIO : public OutputSwitch {
public:
    OutputSwitchGPIO(unsigned int line_number);
    ~OutputSwitchGPIO();

    void set_state(State state) override;

private:
    unsigned int _line_number;
};
#pragma once

#include "light-barrier.h"
#include <string>
#include <gpiod.hpp>


class LightBarrierGPIO : public LightBarrier
{
    public:
    LightBarrierGPIO(const std::string& gpiodevice, int line_number);
    
    State get_state() const override;


    private:
    std::string _gpiodevice;
    int _line_number;
    gpiod::line _line;
    gpiod::chip _chip;

};  


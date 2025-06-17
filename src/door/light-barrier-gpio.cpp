#include "light-barrier-gpio.h"
#include <stdexcept>
#include <cstdlib>
#include <filesystem>
#include <gpiod.hpp>
#include <iostream>

namespace   
{
const ::std::filesystem::path chip_path("/dev/gpiochip0");

} 

LightBarrierGPIO::LightBarrierGPIO(const std::string& gpiodevice, int line_number)
    : _gpiodevice(gpiodevice), _line_number(line_number)
{

    _line = _chip.get_line(_line_number);

    _line.request({"light_barrier_gpio",gpiod::line_request::DIRECTION_INPUT});
}

LightBarrier::State LightBarrierGPIO::get_state() const
{
    int value = _line.get_value();

    if (value == 1) 
    {
        return State::BEAM_SOLID;
    } 
    else 
     {
        return State::BEAM_BROKEN;
     }
}
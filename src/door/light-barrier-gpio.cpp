#include "light-barrier-gpio.h"
#include <stdexcept>
#include <cstdlib>
#include <filesystem>
#include <gpiod.hpp>
#include <iostream>


LightBarrierGPIO::LightBarrierGPIO(const std::string& gpiodevice, int line_number)
    : _gpiodevice(gpiodevice), _chip(gpiodevice),  _line(_chip.get_line(line_number))
{

    _line.request({"light_barrier_gpio",gpiod::line_request::DIRECTION_INPUT});
}

LightBarrier::State LightBarrierGPIO::get_state() const
{
    int value = _line.get_value();

    return (value == 1) ? State::BEAM_SOLID : State::BEAM_BROKEN;
}
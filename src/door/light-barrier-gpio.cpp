#include "light-barrier-gpio.h"
#include <stdexcept>


LightBarrierGPIO::LightBarrierGPIO(const std::string& gpiodevice, int line_number)
    : _gpiodevice(gpiodevice), _line_number(line_number)
{
   
}

LightBarrier::State LightBarrierGPIO::get_state() const
{
  
}
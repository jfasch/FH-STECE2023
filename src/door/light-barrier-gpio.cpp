#include "light-barrier-gpio.h"
#include <iostream>



LightBarrierGPIO::LightBarrierGPIO(const std::string& gpiodevice, int line_number)
    : _gpiodevice(gpiodevice), _line_number(line_number), _chip(gpiodevice)
{
    try     
    {
        _request = _chip.prepare_request()
                    .set_consumer("light-barrier")
                    .add_line_settings(_line_number,
                                        gpiod::line_settings()
                                        .set_direction(gpiod::line::direction::INPUT))
                    .do_request();
    } 
    catch (const std::exception& error) 
     {
        std::cerr << "LightBarrierGPIO initialization failed: " << error.what() << std::endl;
        throw;
     }

}

LightBarrierGPIO::~LightBarrierGPIO()
{
    _chip.close();
    _request.release();  

}

LightBarrier::State LightBarrierGPIO::get_state() 
{
    auto value = _request.get_value(_line_number);  

    return (value == gpiod::line::value::ACTIVE)
           ? LightBarrier::State::BEAM_SOLID
           : LightBarrier::State::BEAM_BROKEN;
}


#include "input-switch-gpio.h"
#include <string>
#include <stdexcept>
#include <cassert>



InputSwitchGPIO::InputSwitchGPIO(const std::string& gpiodevice, unsigned int* line_number)
    : _gpiodevice(gpiodevice), _line_number(line_number)
{
   _chip = gpiod_chip_open(gpiodevice.c_str());
    if (!_chip)
        throw std::runtime_error("Failed to open GPIO chip");

    settings = gpiod_line_settings_new();
    assert(settings);
    
	gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_INPUT);

	line_cfg = gpiod_line_config_new();
    assert(line_cfg);

    int error = gpiod_line_config_add_line_settings(line_cfg, _line_number, 1, settings);
    assert(!error);

    request = gpiod_chip_request_lines(_chip, nullptr, line_cfg);
    assert(request != nullptr);
}

InputSwitchGPIO::~InputSwitchGPIO()
{
    gpiod_chip_close(_chip);
    gpiod_line_settings_free(settings);
    gpiod_line_config_free(line_cfg);
    gpiod_line_request_release(request);
}


InputSwitch::State InputSwitchGPIO::get_state()
{
    auto value = gpiod_line_request_get_value(request, *_line_number); 
    
    return (value == 1)
              ? InputSwitch::State::INPUT_TRUE
              : InputSwitch::State::INPUT_FALSE;
}


#include "output-switch-gpio.h"
#include <stdexcept>
#include <cassert>

OutputSwitchGPIO::OutputSwitchGPIO(const std::string& gpiodevice, unsigned int line_number)
    : _gpiodevice(gpiodevice), _line_number(line_number)
{
    _chip = gpiod_chip_open(gpiodevice.c_str());
    if (!_chip)
        throw std::runtime_error("Failed to open GPIO chip");

    settings = gpiod_line_settings_new();
    assert(settings);
    gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_OUTPUT);

    line_cfg = gpiod_line_config_new();
    assert(line_cfg);

    int error = gpiod_line_config_add_line_settings(line_cfg, &_line_number, 1, settings);
    assert(!error);

    request = gpiod_chip_request_lines(_chip, nullptr, line_cfg);
    assert(request);
}

OutputSwitchGPIO::~OutputSwitchGPIO()
{
    gpiod_chip_close(_chip);
    gpiod_line_settings_free(settings);
    gpiod_line_config_free(line_cfg);
    gpiod_line_request_release(request);
}

void OutputSwitchGPIO::set_state(State state)
{
    gpiod_line_value value = (state == State::OUTPUT_HIGH) ? GPIOD_LINE_VALUE_ACTIVE : GPIOD_LINE_VALUE_INACTIVE;

    gpiod_line_request_set_value(request, _line_number, value);
}
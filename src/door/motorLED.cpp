#include "motorLED.h"
#include <string>
#include <stdexcept>
#include <cassert>

//Konstruktor
MotorLED::MotorLED(const std::string& gpiodevice, unsigned int line_number_forward, unsigned int line_number_backward){

    //Variablendekleration
    _direction = Direction::IDLE;

    _line_array[0] = line_number_forward;
    _line_array[1] = line_number_backward;

    _values_forward[0] = GPIOD_LINE_VALUE_ACTIVE;
    _values_forward[1] = GPIOD_LINE_VALUE_INACTIVE;

    _values_backward[0] = GPIOD_LINE_VALUE_INACTIVE;
    _values_backward[1] = GPIOD_LINE_VALUE_ACTIVE;

    _values_stop[0] = GPIOD_LINE_VALUE_INACTIVE;
    _values_stop[1] = GPIOD_LINE_VALUE_INACTIVE;


    //Chip-/ Lineconfig
    _chip = gpiod_chip_open(gpiodevice.c_str());
    if (!_chip)
        throw std::runtime_error("Failed to open GPIO chip");

    settings = gpiod_line_settings_new();
    assert(settings);
    
	gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_OUTPUT);

	line_cfg = gpiod_line_config_new();
    assert(line_cfg);

    int error = gpiod_line_config_add_line_settings(line_cfg, _line_array, 2, settings);
    assert(!error);

    request = gpiod_chip_request_lines(_chip, nullptr, line_cfg);
    assert(request != nullptr);
}


//Dekonstruktor
MotorLED::~MotorLED(){

    gpiod_chip_close(_chip);
    gpiod_line_settings_free(settings);
    gpiod_line_config_free(line_cfg);
    gpiod_line_request_release(request);
}

//Funktionsdefinitionen
void MotorLED::forward(){
    
    int error = gpiod_line_request_set_values(request, _values_forward);
    assert(error == 0);

    _direction = Direction::FORWARD;
}

void MotorLED::backward(){

    int error = gpiod_line_request_set_values(request, _values_backward);
    assert(error == 0);

    _direction = Direction::BACKWARD;
}

void MotorLED::stop(){

    int error = gpiod_line_request_set_values(request, _values_stop);
    assert(error == 0);

    _direction = Direction::IDLE;
}

Motor::Direction MotorLED::get_direction() const{

    return _direction;
}
#include "motorLED.h"
#include <string>
#include <stdexcept>

//Konstruktor
MotorLED::MotorLED(const std::string& gpiodevice, int line_number_forward, int line_number_backward, Motor::Direction direction){

    _chip = gpiod_chip_open(gpiodevice.c_str());
    if (!_chip)
        throw std::runtime_error("Failed to open GPIO chip");

    // Hole die GPIO-Leitungen
    _gpio_forward = gpiod_chip_get_line(_chip, line_number_forward);
    _gpio_backward = gpiod_chip_get_line(_chip, line_number_backward);
    if (!_gpio_forward || !_gpio_backward)
        throw std::runtime_error("Failed to get GPIO lines");

    // Richte beide GPIOs als Ausgang ein
    if (gpiod_line_request_output(_gpio_forward, "motorled", 0) < 0)
        throw std::runtime_error("Failed to request GPIO line for forward");

    if (gpiod_line_request_output(_gpio_backward, "motorled", 0) < 0)
        throw std::runtime_error("Failed to request GPIO line for backward");

    //Zuweisung direction
    _direction = direction;
}

//Dekonstruktor C-Stlye
MotorLED::~MotorLED()
{
    gpiod_line_release(_gpio_forward);
    gpiod_line_release(_gpio_backward);
    gpiod_chip_close(_chip);
}

//Funktionsdefinitionen
void MotorLED::forward() {
    gpiod_line_set_value(_gpio_forward, 1);
    gpiod_line_set_value(_gpio_backward, 0);
}

void MotorLED::backward() {
    gpiod_line_set_value(_gpio_forward, 0);
    gpiod_line_set_value(_gpio_backward, 1);
}

void MotorLED::stop() {
    gpiod_line_set_value(_gpio_forward, 0);
    gpiod_line_set_value(_gpio_backward, 0);
}

Motor::Direction MotorLED::get_direction() const{

    return _direction;
}
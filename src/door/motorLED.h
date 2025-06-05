#pragma once

#include <gpiod.h>
#include "motor.h"
#include <string>


class MotorLED : public Motor
{
    public:
        MotorLED(const std::string& gpiodevice, int line_number_forward, int line_number_backward, Motor::Direction direction);
        ~MotorLED();

        void forward();
        void backward();
        void stop();
        Direction get_direction() const;


    private:
        gpiod_chip* _chip;
        gpiod_line* _gpio_forward;
        gpiod_line* _gpio_backward;
        Direction _direction;    

};
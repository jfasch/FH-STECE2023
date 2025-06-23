#pragma once

#include <gpiod.h>
#include "motor.h"
#include <string>

class MotorLED : public Motor
{
    public:
        MotorLED(const std::string& gpiodevice, unsigned int line_number_forward, unsigned int line_number_backward);
        ~MotorLED();

        void forward() override;
        void backward() override;
        void stop() override;
        Direction get_direction() const override;


    private:
        gpiod_chip* _chip;

        gpiod_line_request* request;
        gpiod_line_settings* settings;
        gpiod_line_config* line_cfg;

        unsigned int _line_array[2];
        gpiod_line_value _values_forward[2];
        gpiod_line_value _values_backward[2];
        gpiod_line_value _values_stop[2];

        Direction _direction;
};
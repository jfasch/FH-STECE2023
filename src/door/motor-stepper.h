#pragma once

#include <gpiod.h>
#include "motor.h"
#include <string>

class MotorStepper : public Motor
{
    public:
        MotorStepper(const std::string& gpiodevice, unsigned int line_enable, unsigned int line_dir, std::string period_nanosec, std::string duty_nanosec);
        ~MotorStepper();

        void forward() override;
        void backward() override;
        void stop() override;
        Direction get_direction() const override;


    private:
        int writeData(std::string path, std::string value);
        int ensureExported();

        gpiod_chip* _chip;

        gpiod_line_request* request;
        gpiod_line_settings* settings;
        gpiod_line_config* line_cfg;

        unsigned int _line_array[2];
        gpiod_line_value _values_forward[2];
        gpiod_line_value _values_backward[2];
        gpiod_line_value _values_stop[2];

        Direction _direction;
        std::string _period_nanosec;
        std::string _duty_nanosec;
};
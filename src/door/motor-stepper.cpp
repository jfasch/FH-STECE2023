#include "motor-stepper.h"
#include <string>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>


//Konstruktor
MotorStepper::MotorStepper(const std::string& gpiodevice, unsigned int line_enable, unsigned int line_dir, std::string period_nanosec, std::string duty_nanosec){

    //Variablendekleration
    _direction = Direction::IDLE;
    _period_nanosec = period_nanosec;
    _duty_nanosec = duty_nanosec;

    _line_array[0] = line_enable;
    _line_array[1] = line_dir;

    _values_forward[0] = GPIOD_LINE_VALUE_INACTIVE;
    _values_forward[1] = GPIOD_LINE_VALUE_INACTIVE;

    _values_backward[0] = GPIOD_LINE_VALUE_INACTIVE;
    _values_backward[1] = GPIOD_LINE_VALUE_ACTIVE;

    _values_stop[0] = GPIOD_LINE_VALUE_ACTIVE;
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

    //MotorStepper::ensureExported();
    MotorStepper::stop();
}


//Dekonstruktor
MotorStepper::~MotorStepper(){

    gpiod_chip_close(_chip);
    gpiod_line_settings_free(settings);
    gpiod_line_config_free(line_cfg);
    gpiod_line_request_release(request);
}

//Funktionsdefinitionen
void MotorStepper::forward(){
    
    int error = gpiod_line_request_set_values(request, _values_forward);
    assert(error == 0);

    _direction = Direction::FORWARD;

    writeData("/sys/class/pwm/pwmchip0/pwm0/period", _period_nanosec);
    writeData("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", _duty_nanosec);
    writeData("/sys/class/pwm/pwmchip0/pwm0/enable", "1");
}

void MotorStepper::backward(){

    int error = gpiod_line_request_set_values(request, _values_backward);
    assert(error == 0);

    _direction = Direction::BACKWARD;

    writeData("/sys/class/pwm/pwmchip0/pwm0/period", _period_nanosec);
    writeData("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", _duty_nanosec);
    writeData("/sys/class/pwm/pwmchip0/pwm0/enable", "1");
}

void MotorStepper::stop(){

    int error = gpiod_line_request_set_values(request, _values_stop);
    assert(error == 0);

    _direction = Direction::IDLE;

    writeData("/sys/class/pwm/pwmchip0/pwm0/enable", "0");
}

Motor::Direction MotorStepper::get_direction() const{

    return _direction;
}

// writeData überschreibt zu sendende Daten
int MotorStepper::writeData(std::string path, std::string value) {
    FILE *file = fopen(path.c_str(), "w");
    if (!file) {
        perror("fopen");
        return -1;
    }
    if (fputs(value.c_str(), file) == EOF) {
        perror("fputs");
        fclose(file);
        return -1;
    }
    fclose(file);
    return 0;
}

/*
//stellt sicher das pwm0 exportiert ist
int MotorStepper::ensureExported() {
    struct stat st;
    if (stat("/sys/class/pwm/pwmchip0/pwm0", &st) != 0) {
        // Exportieren, falls pwm0 nicht vorhanden ist
        if (writeData("/sys/class/pwm/pwmchip0/export", "0") < 0) {
            return -1;
        }
    }
    return 0;
}
*/
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "input-switch-gpio-sysfs.h"

static bool write_to_sysfs(const std::string& path, const std::string& value) {
    std::ofstream fs(path);
    if (!fs.is_open()) {
        return false;
    }
    fs << value;
    if (!fs.good()) {
        return false;
    }
    fs.close();
    return true;
}

std::string read_in_sysfs(const std::string& path) {
    std::string level;
    std::ifstream fs(path);
    if (!fs.is_open()) {
        return "";
    }
    std::getline(fs, level);
    if (!fs.good()) {
        return "";
    }
    fs.close();
    return level;
}

InputSwitchGPIOSysfs::InputSwitchGPIOSysfs(unsigned int line_number){
    _line_number = line_number;
    const std::string gpio_str = std::to_string(_line_number);
    const std::string inputPin = "/sys/class/gpio/gpio" + gpio_str;
    const std::string inputDirection = inputPin + "/direction";
    const std::string inputValue = inputPin + "/value";

    write_to_sysfs("/sys/class/gpio/export", gpio_str);
    write_to_sysfs(inputDirection, "in");

    usleep(100000);

    int inputNumber = std::stoi(read_in_sysfs(inputValue));

    (inputNumber == 1) ? _state = State::INPUT_HIGH : _state = State::INPUT_LOW;
}

InputSwitchGPIOSysfs::~InputSwitchGPIOSysfs()
{
    write_to_sysfs("/sys/class/gpio/unexport", std::to_string(_line_number));
}

InputSwitch::State InputSwitchGPIOSysfs::get_state()
{
    const std::string value = (_state == State::INPUT_HIGH) ? "1" : "0";

    return _state;
}
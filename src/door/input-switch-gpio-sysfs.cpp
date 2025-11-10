#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "input-switch-gpio-sysfs.h"
#include "small_file_handling.h"

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

    std::ifstream check_dir(inputPin + "/direction");
    bool already_exported = check_dir.is_open();
    check_dir.close();

    if (!already_exported) {
        write_string_to_file("/sys/class/gpio/export", gpio_str);
        usleep(100000);
    }
    write_string_to_file(inputDirection, "in");
}

InputSwitchGPIOSysfs::~InputSwitchGPIOSysfs()
{
    write_string_to_file("/sys/class/gpio/unexport", std::to_string(_line_number));
}

InputSwitch::State InputSwitchGPIOSysfs::get_state()
{

    const std::string path = "/sys/class/gpio/gpio" + std::to_string(_line_number) + "/value";

    std::string value = read_string_from_file(path); 

    if (value == "1")
        return State::INPUT_HIGH;
    else
        return State::INPUT_LOW;
}

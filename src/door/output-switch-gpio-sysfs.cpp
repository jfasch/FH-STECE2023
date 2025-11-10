#include "output-switch-gpio-sysfs.h"
#include <fstream>
#include <string>
#include <unistd.h> // for usleep

// Helper function to write to a sysfs file
// Returns true on success, false on failure (e.g., cannot open or write file).
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

OutputSwitchGPIO::OutputSwitchGPIO(unsigned int line_number)
    : _line_number(line_number)
{
    // Convert line number to string for sysfs paths.
    const std::string gpio_str = std::to_string(_line_number);
    const std::string gpio_path = "/sys/class/gpio/gpio" + gpio_str;

    // Check if GPIO is already exported by trying to open the direction file.
    std::ifstream check_dir(gpio_path + "/direction");
    bool already_exported = check_dir.is_open();
    check_dir.close();

    if (!already_exported) {
        // Export the GPIO line if not already done.
        write_to_sysfs("/sys/class/gpio/export", gpio_str);

        // A small delay might be needed for the sysfs directory to be created.
        usleep(100000); // 100ms
    }

    write_to_sysfs(gpio_path + "/direction", "out");
}

OutputSwitchGPIO::~OutputSwitchGPIO()
{
    write_to_sysfs("/sys/class/gpio/unexport", std::to_string(_line_number));
}

void OutputSwitchGPIO::set_state(State state)
{
    const std::string value = (state == State::OUTPUT_HIGH) ? "1" : "0";
    write_to_sysfs("/sys/class/gpio/gpio" + std::to_string(_line_number) + "/value", value);
}

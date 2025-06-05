#include <gpiod.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <cassert>


int main(int argc, char** argv)
{
    std::string gpiodev = argv[1];
    unsigned int line = std::stoi(argv[2]);

    auto chip = gpiod_chip_open(gpiodev.c_str());
	if (!chip) {
        perror("gpiod_chip_open");
        return 1;
    }

	auto settings = gpiod_line_settings_new();
    assert(settings);
    
	gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_INPUT);

	auto line_cfg = gpiod_line_config_new();
    assert(line_cfg);

    int error = gpiod_line_config_add_line_settings(line_cfg, &line, 1, settings);
    assert(!error);

    auto request = gpiod_chip_request_lines(chip, nullptr, line_cfg);
    assert(request != nullptr);

    while (true) {
        auto value = gpiod_line_request_get_value(request, line);
        if (value == GPIOD_LINE_VALUE_ACTIVE)
            std::cout << "active" << std::endl;
        else if (value == GPIOD_LINE_VALUE_INACTIVE)
            std::cout << "inactive" << std::endl;
        else 
            assert("wtf?");

        sleep(1);
    }    

    return 0;
}

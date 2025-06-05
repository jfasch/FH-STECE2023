#include <gpiod.hpp>
#include <string>
#include <unistd.h>


int main(int argc, char** argv)
{
    std::string gpiodev = argv[1];
    int gpionum = std::stoi(argv[2]);

	auto chip = gpiod::chip(gpiodev);
    auto request_builder = chip.prepare_request();
    request_builder.set_consumer("fh-door");
    request_builder.add_line_settings(
        gpionum,
        gpiod::line_settings().set_direction(gpiod::line::direction::INPUT));
    auto request = request_builder.do_request();

    while (true) {
        std::cout << request.get_value(gpionum) << std::endl;
        sleep(1);
    }    

    return 0;
}

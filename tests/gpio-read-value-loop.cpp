#include "../src/door/input-switch-gpio.h"
#include <string>
#include <unistd.h>
#include <iostream>


int main(int argc, char** argv)
{
    std::string gpiodev = argv[1];
    unsigned int line = std::stoi(argv[2]);

    InputSwitchGPIO input_switch(gpiodev, &line);

    while (true) {
        auto state = input_switch.get_state();
        if (state == InputSwitch::State::INPUT_HIGH)
            std::cout << "active" << std::endl;
        else if (state == InputSwitch::State::INPUT_LOW)
            std::cout << "inactive" << std::endl;

        sleep(1);
    }    

    return 0;
}

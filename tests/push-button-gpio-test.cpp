#include <iostream>
#include <chrono>
#include <thread>
#include "../src/door/input-switch-gpio.h"

int main() {
    try {
        // Replace 1 with your actual GPIO line number
        unsigned int line_offset = 1;
        std::string chipname = "/dev/gpiochip0";

        // Instantiate the input switch
        InputSwitchGPIO button(chipname, &line_offset);

        std::cout << "Reading GPIO line " << line_offset << " on " << chipname << "...\n";

        // Read and print state 10 times (1s interval)
        for (int i = 0; i < 10; ++i) {
            InputSwitch::State state = button.get_state();
            if (state == InputSwitch::State::INPUT_HIGH)
                std::cout << "State: INPUT_HIGH\n";
            else
                std::cout << "State: INPUT_LOW\n";

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::system_error& e) {
        std::cerr << "System error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

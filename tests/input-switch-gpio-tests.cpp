#include <door/input-switch-gpio.h>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    try {
        // Replace 1 with your actual GPIO line number
        unsigned int line_number = 1;
        std::string chipname = "/dev/gpiochip0";

        // Instantiate the inpuswitch (default state doesn't matter here)
        InputSwitchGPIO inputswitch(chipname, line_number);

        std::cout << "Reading GPIO line " << line_number << " on " << chipname << "...\n";

        // Read and print state 10 times (1s interval)
        for (int i = 0; i < 10; ++i) {
            InputSwitchGPIO::State state = inputswitch.get_state();
            if (state == InputSwitch::State::INPUT_HIGH)
                std::cout << "State: INPUT HIGH\n";
            else
                std::cout << "State: INPUT LOW\n";

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
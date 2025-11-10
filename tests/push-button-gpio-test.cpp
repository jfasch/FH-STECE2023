#include <iostream>
#include <chrono>
#include <thread>
#include <door/push-button-gpio.h>

int main() {
    try {
        // Replace 1 with your actual GPIO line number
        unsigned int line_offset = 1;
        std::string chipname = "/dev/gpiochip0";

        // Instantiate the button (default state doesn't matter here)
        PushButtonGpio button(PushButton::RELEASED, line_offset, chipname);

        std::cout << "Reading GPIO line " << line_offset << " on " << chipname << "...\n";

        // Read and print state 10 times (1s interval)
        for (int i = 0; i < 10; ++i) {
            PushButton::State state = button.get_state();
            if (state == PushButton::PRESSED)
                std::cout << "State: PRESSED\n";
            else
                std::cout << "State: RELEASED\n";

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

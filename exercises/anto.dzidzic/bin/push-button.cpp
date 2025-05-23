#include "push-button.h"
#include <iostream>

int main()
{
    PushButton button;

    PushButton::PushButtonState currentState = button.PushButton_get_state();

    if (currentState == PushButton::PUSHBUTTON_RELEASED) {
        std::cout << "Button is released." << std::endl;
    }

    // Change the button state to PRESSED
    button.PushButton_set_state(PushButton::PUSHBUTTON_PRESSED);

    // Get and print the new state
    currentState = button.PushButton_get_state();
    if (currentState == PushButton::PUSHBUTTON_PRESSED) {
        std::cout << "Button is pressed." << std::endl;
    }

    return 0;

}

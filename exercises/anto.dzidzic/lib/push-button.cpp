#include "push-button.h"
#include <iostream>

int main()
{
    PushButton button;

    PushButtonState currentState = button.PushButton_get_state();

    if (currentState == PUSHBUTTON_RELEASED) {
        std::cout << "Button is released." << std::endl;
    }

    // Change the button state to PRESSED
    button.PushButton_set_state(PUSHBUTTON_PRESSED);

    // Get and print the new state
    currentState = button.PushButton_get_state();
    if (currentState == PUSHBUTTON_PRESSED) {
        std::cout << "Button is pressed." << std::endl;
    }

    return 0;

}

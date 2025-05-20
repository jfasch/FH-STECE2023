#pragma once

enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
public:
    // Constructor replaces PushButton_init()
    PushButton(PushButtonState state);

    // Public methods replacing get/set functions
    PushButtonState getState() const;
    void setState(PushButtonState state);  // used in tests

private:
    PushButtonState state_;
};

#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};


class PushButton
{
private:
    PushButtonState state;

public:
    // Constructor
    PushButton(PushButtonState initialState);

    // Getter for the state
    PushButtonState getState() const;

    // Setter for the state (for tests only)
    void setState(PushButtonState newState);
};

#pragma once

enum class PushButtonState
{
    PRESSED,
    RELEASED,
};

class PushButton
{
public:
    PushButton(PushButtonState state); 
    PushButtonState get_state(); 

    // for tests only
    void set_state(PushButtonState state);

private:
    PushButtonState _state;
};

#pragma once

enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

class PushButton
{
public:
    
    PushButton(PushButtonState state);

    
    PushButtonState getState() const;
    void setState(PushButtonState state);  

private:
    PushButtonState state_;
};

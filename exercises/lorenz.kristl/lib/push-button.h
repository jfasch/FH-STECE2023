/*
#pragma once


enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

struct PushButton
{
    PushButtonState state;
};

void PushButton_init(PushButton* self, PushButtonState state);
PushButtonState PushButton_get_state(PushButton* self);

// for tests only
void PushButton_set_state(PushButton* self, PushButtonState state);
*/

#pragma once

class PushButton
{
public:
    enum class State
    {
        PRESSED,
        RELEASED
    };

    PushButton(State initialState = State::RELEASED);

    State getState() const;
    void setState(State state);

private:
    State state;
};
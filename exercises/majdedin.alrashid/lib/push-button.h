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
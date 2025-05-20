#pragma once

class PushButtonMock
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };

public:
    PushButton(State state);
    State get_state() const;

    // for tests only
    void set_state(State state);

private:
    State _state;
};

#pragma once

class PushButton
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };

public:
    virtual ~PushButton() = default;
    virtual State get_state() const = 0;

    // for tests only
    virtual void set_state(State state) = 0;

private:
    State _state;
};

#pragma once

class PushButton
{
public:
    enum class State
    {
        PRESSED,
        RELEASED,
    };

    virtual ~PushButton() = default;
    virtual State get_state() const = 0;

    // for tests only
    virtual void set_state(State state) = 0;
};

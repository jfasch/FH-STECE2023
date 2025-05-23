#pragma once


class PushButton
{
    public:
    enum State
    {
        PRESSED,
        RELEASED,
    };

    virtual State get_state() const = 0;
    virtual void set_state(State state) = 0;
};
#pragma once

class IPushButton
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };
    
    virtual ~IPushButton() = default;
    virtual State get_state() const = 0;

    // for tests only
    virtual void set_state(State state) = 0;
};
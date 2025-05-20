#pragma once

class LightBarrier
{
    public:

    enum State
    {
        BEAM_SOLID,
        BEAM_BROKEN,
    };

    virtual State get_state() const = 0;
    virtual void set_state(State state) = 0;
};
#pragma once


class LightBarrier
{
public:
    enum class State
        {
            BEAM_SOLID,
            BEAM_BROKEN,
        };

    virtual State get_state() const =0;

    // for tests only
    virtual void set_state(State state) =0;

private:
    State _state;
};


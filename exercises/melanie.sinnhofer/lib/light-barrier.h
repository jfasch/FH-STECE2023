#pragma once

class LightBarrier
{
public:

    enum class State
    {
        BEAM_SOLID,
        BEAM_BROKEN,
    };


    explicit LightBarrier(State state);
    State get_state() const;

    // for tests only
    void set_state(State state);

private:
    State state_;
};
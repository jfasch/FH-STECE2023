#pragma once


class LightBarrierMock
{
public:
    enum class State
        {
            BEAM_SOLID,
            BEAM_BROKEN,
        };

    LightBarrier(State state);
    State get_state() const;

    // for tests only
    void set_state(State state);

private:
    State _state;
};


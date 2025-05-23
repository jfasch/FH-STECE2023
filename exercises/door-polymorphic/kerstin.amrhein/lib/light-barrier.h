#pragma once

class LightBarrier
{
public:
    enum class State
        {
            BEAM_SOLID,
            BEAM_BROKEN,
        };

    virtual ~LightBarrier() = default;
    virtual State get_state() const = 0;

    // for tests only
    virtual void set_state(State state) = 0;
};
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
    virtual State get_state();
};


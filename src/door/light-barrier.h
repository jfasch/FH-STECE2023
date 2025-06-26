#pragma once

class LightBarrier
{
public:
    enum class State
    {
        BEAM_BROKEN,
        BEAM_SOLID,
    };

    virtual ~LightBarrier() = default;
    virtual State get_state() = 0;
};


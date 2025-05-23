#pragma once

class ILightBarrier
{
public:
    enum class State
    {
        BEAM_SOLID,
        BEAM_BROKEN,
    };

    virtual ~ILightBarrier() = default;

    virtual State get_state() const = 0;
};

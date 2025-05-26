#pragma once

class LightBarrier {
public:
    enum class State {
        BEAM_SOLID,
        BEAM_BROKEN,
    };

    virtual ~LightBarrier() = default;

    // reines Interface (abstrakte Methode)
    virtual State get_state() const = 0;
};

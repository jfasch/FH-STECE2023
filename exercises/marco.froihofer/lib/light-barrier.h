#pragma once

enum class LightBarrierState {
    BEAM_SOLID,
    BEAM_BROKEN,
};

class LightBarrier {
public:
    // Konstruktor
    LightBarrier(LightBarrierState state) : _state(state) {}

    // Getter
    LightBarrierState get_state() const {
        return _state;
    }

    // Setter (for tests only)
    void set_state(LightBarrierState state) {
        _state = state;
    }

private:
    LightBarrierState _state;
};

#pragma once

enum class LightBarrierState {
    BEAM_SOLID,
    BEAM_BROKEN
};

class LightBarrier {
public:
    LightBarrier(LightBarrierState state = LightBarrierState::BEAM_SOLID) : state(state) {}

    LightBarrierState getState() const { return state; }
    void setState(LightBarrierState newState) { state = newState; }

private:
    LightBarrierState state;
};

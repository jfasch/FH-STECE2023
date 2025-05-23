#pragma once


enum LightBarrierState
{
    LIGHTBARRIER_BEAM_SOLID,
    LIGHTBARRIER_BEAM_BROKEN,
};

class LightBarrier
{
private:
    LightBarrierState _state;

public:
    // Konstruktor
    LightBarrier(LightBarrierState state = LightBarrierState::LIGHTBARRIER_BEAM_SOLID);

    // Getter
    LightBarrierState state() const;

    // Setter
    void set_state(LightBarrierState state);
};
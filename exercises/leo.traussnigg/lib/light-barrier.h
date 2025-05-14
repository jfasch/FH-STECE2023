#pragma once

class LightBarrier
{
public:
    enum class State
    {
        BeamSolid,
        BeamBroken,
    };

    LightBarrier(State state) : state_(state) {}

    State getState() const { return state_; }
    void setState(State state) { state_ = state; }

private:
    State state_;
};

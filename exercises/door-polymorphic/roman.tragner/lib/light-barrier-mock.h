#pragma once

#include "light-barrier.h"  // Interface einbinden

class LightBarrierMock : public LightBarrier {
public:
    LightBarrierMock(State state);

    State get_state() const;

    // Nur für Tests – ändert den Zustand
    void set_state(State state);

private:
    State _state;
};
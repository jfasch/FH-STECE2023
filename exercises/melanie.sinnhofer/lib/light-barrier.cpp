#include "light-barrier.h"

class LightBarrier {
private:
    LightBarrierState state;

public:
    LightBarrier(LightBarrierState initialState) : state(initialState) {}

    LightBarrierState getState() const {
        return state;
    }

    void setState(LightBarrierState newState) {
        state = newState;
    }
};

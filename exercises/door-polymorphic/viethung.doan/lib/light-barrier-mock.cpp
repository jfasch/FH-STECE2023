#include "light-barrier-mock.h"

LightBarrierMock::LightBarrierMock(State state)
{
    _state = state;
}

LightBarrier::State LightBarrierMock::get_state() const
{
    return _state;
}

void LightBarrierMock::set_state(State state)
{
    _state = state;
}

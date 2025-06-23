#include "light-barrier-mock.h"

LightBarrierMock::LightBarrierMock(State state) : _state(state){}

ILightBarrier::State LightBarrierMock::get_state() const
{
    return _state;
}

void LightBarrierMock::set_state(State state)
{
    _state = state;
}

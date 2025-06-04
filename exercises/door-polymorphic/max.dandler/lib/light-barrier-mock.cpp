#include "light-barrier.h"
#include "light-barrier-mock.h"


LightBarrierMock::LightBarrierMock(LightBarrier::State state)
{
    _state = state;
}

LightBarrier::State LightBarrierMock::get_state() const
{
    return _state;
}

void LightBarrierMock::set_state(LightBarrier::State state)
{
    _state = state;
}

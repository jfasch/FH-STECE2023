#include "light-barrier.h"

/*
void LightBarrier_init(LightBarrier* self, LightBarrierState state)
{
    self->state = state;
}

LightBarrierState LightBarrier_get_state(LightBarrier* self)
{
    return self->state;
}

void LightBarrier_set_state(LightBarrier* self, LightBarrierState state)
{
    self->state = state;
}
*/

LightBarrier::~LightBarrier(){

}

LightBarrier:: LightBarrier(LightBarrierState state){
    this->state = state;
}

LightBarrierState LightBarrier::LightBarrier_get_state()const{
    return state;
}

void LightBarrier::LightBarrier_set_state(LightBarrierState state){
    this->state = state;
}
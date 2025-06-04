#include "door.h"

#include <assert.h>

//door normal

Door::Door(Motor* motor,
    PushButton* do_close,
    PushButton* do_open,
    LightBarrier* closed_position,
    LightBarrier* opened_position)
: motor(motor),
do_close(do_close),
do_open(do_open),
closed_position(closed_position),
opened_position(opened_position),
state(DoorState::INIT)
{
assert(motor->getDirection() == MotorDirection::IDLE);
}

void Door::check()
{
switch (state) {
 case DoorState::INIT: {
     auto closed_state = closed_position->get_state();
     auto opened_state = opened_position->get_state();

     if (closed_state == LightBarrierState::BEAM_SOLID &&
         opened_state == LightBarrierState::BEAM_SOLID)
         state = DoorState::ERROR_MIDDLE_POSITION;
     else if (closed_state == LightBarrierState::BEAM_BROKEN &&
              opened_state == LightBarrierState::BEAM_BROKEN)
         state = DoorState::ERROR_SOMETHING_BADLY_WRONG;
     else if (closed_state == LightBarrierState::BEAM_BROKEN &&
              opened_state == LightBarrierState::BEAM_SOLID)
         state = DoorState::CLOSED;
     else if (closed_state == LightBarrierState::BEAM_SOLID &&
              opened_state == LightBarrierState::BEAM_BROKEN)
         state = DoorState::OPENED;
     else
         assert(!"Invalid barrier state combination");
     break;
 }

 case DoorState::CLOSED: {
     if (do_open->get_state() == PushButtonState::PUSHBUTTON_PRESSED) {
         motor->forward();
         state = DoorState::OPENING;
     }
     break;
 }

 case DoorState::OPENING: {
     if (opened_position->get_state() == LightBarrierState::BEAM_BROKEN) {
         motor->stop();
         state = DoorState::OPENED;
     }
     break;
 }

 case DoorState::OPENED:
 case DoorState::ERROR_MIDDLE_POSITION:
 case DoorState::ERROR_SOMETHING_BADLY_WRONG: {
     assert(false); // not implemented
     break;
 }
}
}

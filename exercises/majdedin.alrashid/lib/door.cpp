#include "door.h"
#include <assert.h>
#include <new>  


// Constructor replaces Door_init
Door::Door(Motor* motor,
           PushButton* do_close, PushButton* do_open,
           LightBarrier* closed_position, LightBarrier* opened_position)
    : motor_(motor),
      do_close_(do_close), do_open_(do_open),
      closed_position_(closed_position), opened_position_(opened_position),
      state_(DOOR_INIT)
{
    assert(motor_->getDirection() == MOTOR_IDLE);
}

// check() replaces Door_check
void Door::check()
{
    switch (state_) {
        case DOOR_INIT: {
            LightBarrierState closed = closed_position_->getState();
            LightBarrierState opened = opened_position_->getState();

            if (closed == LIGHTBARRIER_BEAM_SOLID && opened == LIGHTBARRIER_BEAM_SOLID)
                state_ = DOOR_ERROR_MIDDLE_POSITION;
            else if (closed == LIGHTBARRIER_BEAM_BROKEN && opened == LIGHTBARRIER_BEAM_BROKEN)
                state_ = DOOR_ERROR_SOMETHING_BADLY_WRONG;
            else if (closed == LIGHTBARRIER_BEAM_BROKEN && opened == LIGHTBARRIER_BEAM_SOLID)
                state_ = DOOR_CLOSED;
            else if (closed == LIGHTBARRIER_BEAM_SOLID && opened == LIGHTBARRIER_BEAM_BROKEN)
                state_ = DOOR_OPENED;
            else
                assert(!"Invalid combination of light barrier states");
            break;
        }

        case DOOR_CLOSED: {
            if (do_open_->getState() == PUSHBUTTON_PRESSED) {
                motor_->forward();
                state_ = DOOR_OPENING;
            }
            break;
        }

        case DOOR_OPENING: {
            if (opened_position_->getState() == LIGHTBARRIER_BEAM_BROKEN) {
                motor_->stop();
                state_ = DOOR_OPENED;
            }
            break;
        }

        case DOOR_OPENED:
        case DOOR_ERROR_MIDDLE_POSITION:
        case DOOR_ERROR_SOMETHING_BADLY_WRONG:
            assert(false);
            break;
    }
}

// Optional for tests
DoorState Door::getState() const
{
    return state_;
}

//
// C-style wrappers (optional — only needed if tests still use them)
//
extern "C" 
{

void Door_init(Door* self,
               Motor* motor,
               PushButton* do_close, PushButton* do_open,
               LightBarrier* closed_position, LightBarrier* opened_position)
{
    new (self) Door(motor, do_close, do_open, closed_position, opened_position);
}

void Door_check(Door* self)
{
    self->check();
}

}

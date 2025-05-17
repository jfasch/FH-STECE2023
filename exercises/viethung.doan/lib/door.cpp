#include "door.h"

#include <assert.h>


// Konstruktor
Door::Door(Motor* motor, PushButton* do_close, PushButton* do_open,
    LightBarrier* closed_position, LightBarrier* opened_position)
: _motor(motor), _do_close(do_close), _do_open(do_open),
_closed_position(closed_position), _opened_position(opened_position),
_state(DOOR_INIT)
{
assert(_motor->direction() == MOTOR_IDLE); // Annahme: Motor ist anfangs "IDLE"
}

// Getter
DoorState Door::state() const
{
return _state;
}

// Türlogik
void Door::check()
{
switch (_state)
{
case DOOR_INIT: {
 auto closed = _closed_position->state();
 auto opened = _opened_position->state();

 if (closed == LIGHTBARRIER_BEAM_SOLID && opened == LIGHTBARRIER_BEAM_SOLID)
     _state = DOOR_ERROR_MIDDLE_POSITION;
 else if (closed == LIGHTBARRIER_BEAM_BROKEN && opened == LIGHTBARRIER_BEAM_BROKEN)
     _state = DOOR_ERROR_SOMETHING_BADLY_WRONG;
 else if (closed == LIGHTBARRIER_BEAM_BROKEN && opened == LIGHTBARRIER_BEAM_SOLID)
     _state = DOOR_CLOSED;
 else if (closed == LIGHTBARRIER_BEAM_SOLID && opened == LIGHTBARRIER_BEAM_BROKEN)
     _state = DOOR_OPENED;
 else
     assert(!"unbekannter Zustand");
 break;
}

case DOOR_CLOSED: {
 if (_do_open->state() == PUSHBUTTON_PRESSED) {
     _motor->forward();
     _state = DOOR_OPENING;
 }
 break;
}

case DOOR_OPENING: {
 if (_opened_position->state() == LIGHTBARRIER_BEAM_BROKEN) {
     _motor->stop();
     _state = DOOR_OPENED;
 }
 break;
}

case DOOR_OPENED:
case DOOR_ERROR_MIDDLE_POSITION:
case DOOR_ERROR_SOMETHING_BADLY_WRONG:
 assert(false); // für Debug: Fehlerzustand nicht erlaubt
 break;
}
}
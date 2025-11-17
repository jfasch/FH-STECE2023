#include "door.h"

#include <assert.h>

Door::Door()
{
    _state = State::INIT;
}

output_t Door::init(const input_t input)
{
    if ((input.sensor_closed == InputSwitch::State::INPUT_LOW) && !(input.sensor_open == InputSwitch::State::INPUT_HIGH))
    {
        _state = State::CLOSED;
    }
    else
    {
        _state = State::ERROR_MIDDLE_POSITION;
    }

    output_t output;
    output.motor_direction = Motor::Direction::IDLE;

    return output;
}

output_t Door::cyclic(const events_t events)
{
    output_t output;

    switch(_state)
    {
        case State::INIT:

            output.motor_direction = Motor::Direction::IDLE;
            _state = State::ERROR_SOMETHING_BADLY_WRONG;
            break;

        case State::CLOSED:

            output.motor_direction = Motor::Direction::IDLE;

            if (events.open_button_pressed == EdgeDetector::RISING)
            {
                output.motor_direction = Motor::Direction::FORWARD; // could also be BACKWARD, depends on the implemented hardware
                _state = State::OPENING;
            }
            break;

        case State::OPENING:
            // overcurrent detection

            if (events.light_barrier_open == EdgeDetector::RISING) // could also be FALLING, depends on the implemented hardware
            {
                output.motor_direction = Motor::Direction::IDLE;
                _state = State::OPENED;
            }
            break;

        case State::OPENED:

            if (events.light_barrier_closed == EdgeDetector::RISING)
            {
                output.motor_direction = Motor::Direction::BACKWARD; // could also be FORWARD, depends on the implemented hardware
                _state = State::CLOSING;
            }
            
        break;

        default:
            break;
    }

    output.motor_direction = Motor::Direction::IDLE;
    return output;
}

/*
Door::Door(Motor* motor, 
           InputSwitch* do_close, InputSwitch* do_open, 
           InputSwitch* closed_position, InputSwitch* opened_position)
{
    // assume that the motor is idle when the software boots. FIXME:
    // is that assumption safe?
    assert(motor->get_direction() == Motor::Direction::IDLE);

    _motor = motor;
    _do_close = do_close;
    _do_open = do_open;
    _closed_position = closed_position;
    _opened_position = opened_position;

    _state = State::INIT;
}
*/

/*
void Door::check()
{
    switch (_state) {
        case State::INIT: {
            // figure out the state we are in: where is the door?
            InputSwitch::State closed_barrier_state = _closed_position->get_state();
            InputSwitch::State opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == InputSwitch::State::INPUT_LOW && opened_barrier_state == InputSwitch::State::INPUT_LOW)
                _state = State::ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == InputSwitch::State::INPUT_HIGH && opened_barrier_state == InputSwitch::State::INPUT_HIGH)
                _state = State::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == InputSwitch::State::INPUT_HIGH && opened_barrier_state == InputSwitch::State::INPUT_LOW)
                _state = State::CLOSED;
            else if (closed_barrier_state == InputSwitch::State::INPUT_LOW && opened_barrier_state == InputSwitch::State::INPUT_HIGH)
                _state = State::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case State::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == InputSwitch::State::PRESSED) {
                _motor->forward();
                _state = State::OPENING;
            }

            // FIXME: what if user pressed "do_close" at the same
            // time?

            // FIXME: invariants
            break;
        }
        case State::OPENING: {
            // see if we already reached the end position. if so, stop
            // motor and adjust door state.
            InputSwitch::State opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == InputSwitch::State::INPUT_HIGH) {
                _motor->stop();
                _state = State::OPENED;
            }

            // FIXME: invariants
            break;
        }
        case State::OPENED: {
            assert(false);
            break;
        }
        case State::ERROR_MIDDLE_POSITION: {
            assert(false);
            break;
        }
        case State::ERROR_SOMETHING_BADLY_WRONG: {
            assert(false);
            break;
        }
    }
}
*/

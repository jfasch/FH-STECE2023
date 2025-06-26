#include "door.h"

#include <assert.h>

Door::Door()
{
    _state = State::INIT;
}

output_t Door::init(const input_t input)
{
    if (input.sensor_closed && !input.sensor_opened)
    {
        _state = State::CLOSED;
    }
    else
    {
        _state = State::ERROR_MIDDLE_POSITION;
    }

    output_t output;
    output.motor_backward = false;
    output.motor_forward = false;
    output.display = false;

    return output;
}

output_t Door::cyclic(const events_t events)
{
    switch(_state)
    {
        case State::INIT:
            _state = State::ERROR_SOMETHING_BADLY_WRONG;
            break;

        case State::CLOSED:
            if (events.open_button_pressed)
            {
                _state = State::OPENING;
            }
            break;

        default:
            break;
    }

    output_t output;
    return output;
}

/*
Door::Door(Motor* motor, 
           PushButton* do_close, PushButton* do_open, 
           LightBarrier* closed_position, LightBarrier* opened_position)
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
            LightBarrier::State closed_barrier_state = _closed_position->get_state();
            LightBarrier::State opened_barrier_state = _opened_position->get_state();

            if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && opened_barrier_state == LightBarrier::State::BEAM_SOLID)
                _state = State::ERROR_MIDDLE_POSITION;   // FIXME: recover from that
            else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && opened_barrier_state == LightBarrier::State::BEAM_BROKEN)
                _state = State::ERROR_SOMETHING_BADLY_WRONG;
            else if (closed_barrier_state == LightBarrier::State::BEAM_BROKEN && opened_barrier_state == LightBarrier::State::BEAM_SOLID)
                _state = State::CLOSED;
            else if (closed_barrier_state == LightBarrier::State::BEAM_SOLID && opened_barrier_state == LightBarrier::State::BEAM_BROKEN)
                _state = State::OPENED;
            else 
                assert(!"well, two bits make four values");
            break;
        }
        case State::CLOSED: {
            // "open" requested (button press). drive motor, and
            // switch state to "opening"
            if (_do_open->get_state() == PushButton::State::PRESSED) {
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
            LightBarrier::State opened_barrier_state = _opened_position->get_state();
            if (opened_barrier_state == LightBarrier::State::BEAM_BROKEN) {
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
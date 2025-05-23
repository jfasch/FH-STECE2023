#include "door.h"
#include <cassert>

Door::Door(IMotor* motor,
           IPushButton* close_button, IPushButton* open_button,
           ILightBarrier* closed_sensor, ILightBarrier* opened_sensor)
{
    assert(motor->get_direction() == IMotor::Direction::IDLE);

    _motor = motor;
    _close_button = close_button;
    _open_button = open_button;
    _closed_sensor = closed_sensor;
    _opened_sensor = opened_sensor;

    // Direkter initialer Zustand basierend auf Lichtschranken
    auto closed = _closed_sensor->get_state();
    auto opened = _opened_sensor->get_state();

    if (closed == ILightBarrier::State::BEAM_BROKEN &&
        opened == ILightBarrier::State::BEAM_SOLID)
        _state = State::CLOSED;
    else if (closed == ILightBarrier::State::BEAM_SOLID &&
             opened == ILightBarrier::State::BEAM_BROKEN)
        _state = State::OPENED;
    else
        _state = State::CLOSING;  // Fallback – logischer Fehler oder undefinierter Zustand
}

void Door::check()
{
    switch (_state) {
        case State::CLOSED: {
            if (_open_button->get_state() == IPushButton::State::PRESSED) {
                _motor->forward();
                _state = State::OPENING;
            }
            break;
        }

        case State::OPENING: {
            if (_opened_sensor->get_state() == ILightBarrier::State::BEAM_BROKEN) {
                _motor->stop();
                _state = State::OPENED;
            }
            break;
        }

        case State::OPENED: {
            if (_close_button->get_state() == IPushButton::State::PRESSED) {
                _motor->backward();
                _state = State::CLOSING;
            }
            break;
        }

        case State::CLOSING: {
            if (_closed_sensor->get_state() == ILightBarrier::State::BEAM_BROKEN) {
                _motor->stop();
                _state = State::CLOSED;
            }
            break;
        }
    }
}

Door::State Door::get_state() const {
    return _state;
}

#include "motor-mock.h"

void MockMotor::forward()
{
    _direction = Direction::FORWARD;
}

void MockMotor::backward()
{
    _direction = Direction::BACKWARD;
}

void MockMotor::stop()
{
    _direction = Direction::IDLE;
}

MockMotor::Direction MockMotor::get_direction() const
{
    return _direction;
}

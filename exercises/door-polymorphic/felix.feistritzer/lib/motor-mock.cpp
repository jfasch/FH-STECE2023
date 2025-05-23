#include "motor-mock.h"


MockMotor::MockMotor(Motor::Direction direction)
{
    _direction = direction;
}

void MockMotor::forward()
{
    _direction = Motor::Direction::FORWARD;
}

void MockMotor::backward()
{
    _direction = Motor::Direction::BACKWARD;
}

void MockMotor::stop()
{
    _direction = Motor::Direction::IDLE;
}

Motor::Direction MockMotor::get_direction() const
{
    return _direction;
}

#include "motor-Mock.h"


MotorMock::MotorMock(Direction direction)
{
    _direction = direction;
}

void MotorMock::forward()
{
    _direction = Direction::FORWARD;
}

void MotorMock::backward()
{
    _direction = Direction::BACKWARD;
}

void MotorMock::stop()
{
    _direction = Direction::IDLE;
}

MotorMock::Direction MotorMock::get_direction() const
{
    return _direction;
}

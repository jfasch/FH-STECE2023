#include "motor-mock.h"


MotorMock::MotorMock(IMotor::Direction direction)
{
    _direction = direction;
}

void MotorMock::forward()
{
    _direction = IMotor::Direction::FORWARD;
}

void MotorMock::backward()
{
    _direction = IMotor::Direction::BACKWARD;
}

void MotorMock::stop()
{
    _direction = IMotor::Direction::IDLE;
}

IMotor::Direction MotorMock::get_direction() const
{
    return _direction;
}

#include "motor.h"

Motor::Motor(MotorDirection direction)
{
    _direction = direction;
}

void Motor::forward()
{
    _direction = MotorDirection::FORWARD;
}

void Motor::backward()
{
    _direction = MotorDirection::BACKWARD;
}

void Motor::stop()
{
    _direction = MotorDirection::IDLE;
}

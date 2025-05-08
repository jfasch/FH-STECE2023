#include "motor.h"

void Motor::forward()
{
    _direction = FORWARD;
}

void Motor::backward()
{
    _direction = BACKWARD;
}

void Motor::stop()
{
    _direction = IDLE;
}

Motor::MotorDirection Motor::get_direction()
{
    return _direction;
}

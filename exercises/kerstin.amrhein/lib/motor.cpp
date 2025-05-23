#include "motor.h"


Motor::Motor(MotorDirection init_direction)
{
    _direction = init_direction;
}

void Motor::forward()
{
    _direction = MOTOR_FORWARD;
}

void Motor::backward()
{
    _direction = MOTOR_BACKWARD;
}

void Motor::stop()
{
    _direction = MOTOR_IDLE;
}

MotorDirection Motor::get_direction()
{
    return _direction;
}

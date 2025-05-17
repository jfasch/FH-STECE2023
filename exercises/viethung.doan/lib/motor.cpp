#include "motor.h"


Motor::Motor(MotorDirection direction)
{
    _direction = direction;
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

MotorDirection Motor::direction() const 
{
    return _direction;
}
#include "motor.h"


Motor::Motor(MotorDirection direction)
{
    _direction = direction;
}

void Motor::_forward()
{
    _direction = MOTOR_FORWARD;
}

void Motor::_backward()
{
    _direction = MOTOR_BACKWARD;
}

void Motor::_stop()
{
    _direction = MOTOR_IDLE;
}

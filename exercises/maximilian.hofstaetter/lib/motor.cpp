#include "motor.h"

Motor::~Motor(){}

Motor::Motor(MotorDirection direction)
{
    _direction = direction;
}

void Motor::Motor_forward()
{
    _direction = MOTOR_FORWARD;
}

void Motor::Motor_backward()
{
    _direction = MOTOR_BACKWARD;
}

void Motor::Motor_stop()
{
    _direction = MOTOR_IDLE;
}

MotorDirection Motor::Motor_get_direction() const
{
    return _direction;
}

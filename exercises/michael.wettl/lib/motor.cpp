#include "motor.h"

Motor::Motor(MotorDirection direction)
{
    _direction = direction;
}

void Motor::Motor_forward()
{
    _direction = MotorDirection::MOTOR_FORWARD;
}

void Motor::Motor_backward()
{
    _direction = MotorDirection::MOTOR_BACKWARD;
}

void Motor::Motor_stop()
{
    _direction = MotorDirection::MOTOR_IDLE;
}



#include "motor.h"

Motor::Motor(MotorDirection initialDirection)
{
    direction = initialDirection;
}

void Motor::Motor_forward()
{
    Motor::direction = MOTOR_FORWARD;
}

void Motor::Motor_backward()
{
    direction = MOTOR_BACKWARD;
}

void Motor::Motor_stop()
{
    direction = MOTOR_IDLE;
}

MotorDirection Motor::Motor_get_direction() const
{
    return direction;
}
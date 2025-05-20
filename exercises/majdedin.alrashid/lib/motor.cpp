#include "motor.h"

Motor::Motor(MotorDirection direction)
    : direction_(direction)
{
}

void Motor::forward()
{
    direction_ = MOTOR_FORWARD;
}

void Motor::backward()
{
    direction_ = MOTOR_BACKWARD;
}

void Motor::stop()
{
    direction_ = MOTOR_IDLE;
}

MotorDirection Motor::getDirection() const
{
    return direction_;
}

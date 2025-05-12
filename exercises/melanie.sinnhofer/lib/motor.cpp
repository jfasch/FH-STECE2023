#include "motor.h"

// C++ class implementation for Motor

Motor::Motor(MotorDirection direction)
    : direction(direction) // Use initializer list
{
}

void Motor::forward()
{
    direction = MOTOR_FORWARD;
}

void Motor::backward()
{
    direction = MOTOR_BACKWARD;
}

void Motor::stop()
{
    direction = MOTOR_IDLE;
}

MotorDirection Motor::getDirection() const
{
    return direction;
}

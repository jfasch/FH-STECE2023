#include "motor.h"

Motor::Motor() : direction(MotorDirection::IDLE) {}

Motor::Motor(MotorDirection direction) : direction(direction) {}

void Motor::init(MotorDirection direction)
{
    this->direction = direction;
}

void Motor::forward()
{
    direction = MotorDirection::FORWARD;
}

void Motor::backward()
{
    direction = MotorDirection::BACKWARD;
}

void Motor::stop()
{
    direction = MotorDirection::IDLE;
}

MotorDirection Motor::getDirection() const
{
    return direction;
}

#include "motor.h"

Motor::Motor(Direction initialdirection)
    : direction(initialdirection)
{
}

Motor::Direction Motor::getDirection() const
{
    return direction;
}

void Motor::forward()
{
    direction = Direction::FORWARD;
}

void Motor::backward()
{
    direction = Direction::BACKWARD;
}

void Motor::stop()
{
    direction = Direction::IDLE;
}
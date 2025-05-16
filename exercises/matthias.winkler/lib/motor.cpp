#include "motor.h"


Motor::Motor(MotorDirection direction) : direction(direction) {}

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

MotorDirection Motor::get_direction() const
{
    return direction;
}

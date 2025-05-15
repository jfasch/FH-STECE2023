#include "motor.h"


Motor::Motor(MotorDirection direction): _direction(direction)
{
}

void Motor::forward()
{
    _direction = MotorDirection::FORWARD;
}

void Motor::backward()
{
    _direction = MotorDirection::BACKWARD;
}

void Motor::stop()
{
    _direction = MotorDirection::IDLE;
}

MotorDirection Motor::get_direction() const
{
    return _direction;
}



/*
void Motor_init(Motor* self, MotorDirection direction)
{
    self->direction = direction;
}

void Motor_forward(Motor* self)
{
    self->direction = MOTOR_FORWARD;
}

void Motor_backward(Motor* self)
{
    self->direction = MOTOR_BACKWARD;
}

void Motor_stop(Motor* self)
{
    self->direction = MOTOR_IDLE;
}

MotorDirection Motor_get_direction(Motor* self)
{
    return self->direction;
}
*/
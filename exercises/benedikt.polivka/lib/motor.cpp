#include "motor.h"

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

Motor::Motor(MotorDirection direction)
{
    _direction = direction;
}

Motor::~Motor()
{
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
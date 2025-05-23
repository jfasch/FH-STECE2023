#include "motor.h"

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
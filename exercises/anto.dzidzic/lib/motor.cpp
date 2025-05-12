#include "motor.h"

Motor::Motor(MotorDirection direction)
    : direction(direction)
{
    
}

// Set motor to forward direction
void Motor::forward()
{
    direction = MOTOR_FORWARD;
}

// Set motor to backward direction
void Motor::backward()
{
    direction = MOTOR_BACKWARD;
}

void Motor::stop()
{
    direction = MOTOR_IDLE;
}

// Get the current motor direction
MotorDirection Motor::getdirection() const
{
    return direction;
}

//void Motor_init(Motor* self, MotorDirection direction)
//{
//    self->direction = direction;
//}
//
//void Motor_forward(Motor* self)
//{
//    self->direction = MOTOR_FORWARD;
//}
//
//void Motor_backward(Motor* self)
//{
//    self->direction = MOTOR_BACKWARD;
//}
//
//void Motor_stop(Motor* self)
//{
//    self->direction = MOTOR_IDLE;
//}
//
//MotorDirection Motor_get_direction(Motor* self)
//{
//    return self->direction;
//}

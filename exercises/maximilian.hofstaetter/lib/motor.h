#pragma once


enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

struct Motor
{
    MotorDirection direction;
};

void Motor_init(Motor* self, MotorDirection direction);
void Motor_forward(Motor* self);
void Motor_backward(Motor* self);
void Motor_stop(Motor* self);

// for tests only
MotorDirection Motor_get_direction(Motor* self);

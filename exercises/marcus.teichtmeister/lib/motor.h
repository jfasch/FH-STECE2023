#pragma once

enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

class Motor
{
    public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void stop() = 0;
};
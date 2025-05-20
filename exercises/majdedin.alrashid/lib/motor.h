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
    // Constructor replaces Motor_init()
    Motor(MotorDirection direction = MOTOR_IDLE);

    void forward();     // replaces Motor_forward
    void backward();    // replaces Motor_backward
    void stop();        // replaces Motor_stop

    // for tests
    MotorDirection getDirection() const;

private:
    MotorDirection direction_;
};

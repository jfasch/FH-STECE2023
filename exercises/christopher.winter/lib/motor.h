#pragma once


enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};


class Motor
{
private:
    MotorDirection direction;

public:
    // Constructor
    Motor(MotorDirection initialDirection);

    void Motor_forward();

    void Motor_backward();

    void Motor_stop();

    MotorDirection Motor_get_direction() const;


};

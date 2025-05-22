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
    MotorDirection _direction;

public:
    Motor(MotorDirection _direction);
    void forward();
    void backward();
    void stop();

    // for test only
    MotorDirection get_direction();
};

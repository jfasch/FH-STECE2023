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
    Motor(MotorDirection init_direction);

    void forward();
    void backward();
    void stop();

    // for tests only
    MotorDirection get_direction();
};




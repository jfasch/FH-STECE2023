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
    Motor(MotorDirection direction);
    void _forward();
    void _backward();
    void _stop();

    MotorDirection Motor_get_direction() const {return _direction;};
};
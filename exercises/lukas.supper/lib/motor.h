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
    ~Motor();
    MotorDirection get_direction(){return this->_direction;}
    void forward(){this->_direction = MOTOR_FORWARD;}
    void backward(){this->_direction = MOTOR_BACKWARD;}
    void stop(){this->_direction = MOTOR_IDLE;}
};

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
    Motor(MotorDirection direction) {_direction = direction;}
    void forward() {_direction = MOTOR_FORWARD;}
    void backward() {_direction = MOTOR_BACKWARD;}
    void stop() {_direction = MOTOR_IDLE;}


    MotorDirection get_direction() const {return _direction;}

};


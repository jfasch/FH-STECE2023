#pragma once
#include <motor.h>

class MotorMock : public Motor
{
    private:
    MotorDirection _direction;

    public:
    MotorMock(MotorDirection direction) {_direction = direction;}

    void forward() {_direction = MOTOR_FORWARD;}
    void backward() {_direction = MOTOR_BACKWARD;}
    void stop() {_direction = MOTOR_IDLE;}

    MotorDirection get_direction() const {return _direction;}
};

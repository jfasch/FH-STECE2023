#pragma once
#include <motor.h>

class MotorMock : public Motor
{
    private:
    Motor::Direction _direction;

    public:
    MotorMock(Motor::Direction direction) {_direction = direction;}

    void forward() {_direction = FORWARD;}
    void backward() {_direction = BACKWARD;}
    void stop() {_direction = IDLE;}

    Motor::Direction get_direction() const {return _direction;}
};

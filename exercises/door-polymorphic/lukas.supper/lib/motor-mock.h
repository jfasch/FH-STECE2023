#pragma once
#include "motor.h"


class MotorMock: public Motor
{
public:

    MotorMock(Motor::Direction direction);
    void forward();
    void backward();
    void stop();

    // for tests only? (Door uses for a sanity check)
    Direction get_direction() const;

    ~MotorMock(){};

    private:
    Motor::Direction _direction;
};


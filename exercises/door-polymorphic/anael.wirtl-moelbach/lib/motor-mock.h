#pragma once
#include "motor.h"  

class MotorMock : public IMotor
{
public:
    MotorMock(Direction dir = Direction::IDLE) : _direction(dir) {}

    void forward() override { _direction = Direction::FORWARD; }
    void backward() override { _direction = Direction::BACKWARD; }
    void stop() override { _direction = Direction::IDLE; }

    Direction get_direction() const override { return _direction; }

private:
    Direction _direction;
};


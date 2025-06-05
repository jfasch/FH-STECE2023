#pragma once

#include "motor.h"

class MotorMock : public Motor
{
public:
    MotorMock(Motor::Direction direction);

    void forward() override;
    void backward() override;
    void stop() override;

    Motor::Direction get_direction() const override;

private:
    Motor::Direction _direction;
};


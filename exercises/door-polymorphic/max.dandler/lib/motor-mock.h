#pragma once

#include "motor.h"


class MotorMock : public Motor
{
public:
    MotorMock(Motor::Direction direction);
    void forward() override;
    void backward() override;
    void stop() override;

    // for tests only? (Door uses for a sanity check)
    Motor::Direction get_direction() const override;

private:
    Motor::Direction _direction;
};


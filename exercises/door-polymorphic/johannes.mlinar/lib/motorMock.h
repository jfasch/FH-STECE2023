#pragma once

#include "motor.h"
class MotorMock :public Motor
{
public:
    MotorMock(Direction direction);
    void forward() override;
    void backward() override;
    void stop() override;
    // Destructor
    ~MotorMock() override;
    // for tests only? (Door uses for a sanity check)
    Motor::Direction get_direction() const override;

private:
    Direction _direction;
};


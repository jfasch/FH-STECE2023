#pragma once

#include "motor.h"

class MotorMock : public IMotor
{
public:

    explicit MotorMock(Direction direction);

    void forward() override;
    void backward() override;
    void stop() override;

    // for tests only? (Door uses for a sanity check)
    IMotor::Direction get_direction() const override;

    Direction internal_direction() const { return _direction; }

private:
    Direction _direction;
};


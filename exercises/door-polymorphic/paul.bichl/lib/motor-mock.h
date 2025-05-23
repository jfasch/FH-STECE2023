#pragma once

#include "motor.h"

class MockMotor : public Motor
{
public:
    MockMotor(Motor::Direction direction) : _direction(direction) {}
    virtual void forward() override;
    virtual void backward() override;
    virtual void stop() override;

    // for tests only? (Door uses for a sanity check) => no idea what this means
    Direction get_direction() const override;

private:
    Direction _direction;
};

#pragma once
#include "motor.h"

class Motor_Mock : public Motor
{
public:

    Motor_Mock(Motor::Direction direction);
    virtual void forward() override;
    virtual void backward() override;
    virtual void stop() override;

    // for tests only? (Door uses for a sanity check)
    virtual Direction get_direction() const override;

private:
    Direction _direction;
};


#pragma once

#include <motor.h>

class MockMotor: public Motor
{
public:
    MockMotor(Motor::Direction direction = Motor::Direction::IDLE);

    void forward() override;
    void backward() override;
    void stop() override;

private:
    Motor::Direction _direction;
}
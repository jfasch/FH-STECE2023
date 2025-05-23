#pragma once

#include <motor.h>

class MotorMock : public Motor
{
public:
    MotorMock(Direction direction) : _direction(direction) {}
    void forward() {_direction = Direction::FORWARD;}
    void backward() {_direction = Direction::BACKWARD;}
    void stop() {_direction = Direction::IDLE;}

    // for tests only? (Door uses for a sanity check)
    Direction get_direction() const { return _direction; }

private:
    Direction _direction;
};

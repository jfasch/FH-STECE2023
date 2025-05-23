#include "motor-mock.h"


Motor_Mock::Motor_Mock(Direction direction)
{
    _direction = direction;
}

void Motor_Mock::forward()
{
    _direction = Direction::FORWARD;
}

void Motor_Mock::backward()
{
    _direction = Direction::BACKWARD;
}

void Motor_Mock::stop()
{
    _direction = Direction::IDLE;
}

Motor::Direction Motor_Mock::get_direction() const
{
    return _direction;
}

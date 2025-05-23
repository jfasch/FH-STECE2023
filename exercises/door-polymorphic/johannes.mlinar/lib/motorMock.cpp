#include "motorMock.h"
#include "motorMock.h"

MotorMock::MotorMock(Motor::Direction direction)
{
    _direction = direction;
}

void MotorMock::forward()
{
    _direction = Motor::Direction::FORWARD;
}

void MotorMock::backward()
{
    _direction = Motor::Direction::BACKWARD;
}

void MotorMock::stop()
{
    _direction = Motor::Direction::IDLE;
}

Motor::Direction MotorMock::get_direction() const
{
    return _direction;
}

MotorMock::~MotorMock()
{
    // Destructor implementation (if needed)
}
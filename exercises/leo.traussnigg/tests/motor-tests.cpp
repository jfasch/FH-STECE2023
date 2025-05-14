#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(Motor::Direction::IDLE);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::IDLE);
    }
    {
        Motor motor(Motor::Direction::FORWARD);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::FORWARD);
    }
    {
        Motor motor(Motor::Direction::BACKWARD);
        ASSERT_EQ(motor.getDirection(), Motor::Direction::BACKWARD);
    }
}

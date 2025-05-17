#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(MotorDirection::IDLE);
        ASSERT_EQ(motor.getDirection(), MotorDirection::IDLE);
    }
    {
        Motor motor(MotorDirection::FORWARD);
        ASSERT_EQ(motor.getDirection(), MotorDirection::FORWARD);
    }
    {
        Motor motor(MotorDirection::BACKWARD);
        ASSERT_EQ(motor.getDirection(), MotorDirection::BACKWARD);
    }
}

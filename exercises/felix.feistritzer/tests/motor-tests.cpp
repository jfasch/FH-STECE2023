#include <motor.h>

#include <gtest/gtest.h>


TEST(motor_suite, init)
{
    {
        Motor motor(MotorDirection::IDLE);
        ASSERT_EQ(motor.get_direction(), MotorDirection::IDLE);
    }
    {
        Motor motor(MotorDirection::FORWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::FORWARD);
    }
    {
        Motor motor(MotorDirection::BACKWARD);
        ASSERT_EQ(motor.get_direction(), MotorDirection::BACKWARD);
    }
}

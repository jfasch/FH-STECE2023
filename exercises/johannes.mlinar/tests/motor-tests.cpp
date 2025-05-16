#include <gtest/gtest.h>
#include "motor.h"

TEST(MotorTestSuite, init)
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

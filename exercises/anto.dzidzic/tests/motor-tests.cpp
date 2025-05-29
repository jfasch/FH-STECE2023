#include "motor.h"
#include <gtest/gtest.h>
//asdasd

TEST(MotorTestSuite, DirectionChanges) {
    Motor motor;

    motor.forward();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_FORWARD);

    motor.backward();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_BACKWARD);

    motor.stop();
    ASSERT_EQ(motor.getDirection(), Motor::MOTOR_IDLE);
}

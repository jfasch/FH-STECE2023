#include "../src/door/motorLED.h"
#include <gtest/gtest.h>
#include <unistd.h>

class MotorLEDTest : public ::testing::Test {
protected:
    MotorLED* motorled;
    Motor* motor;

    void SetUp() override {
        motorled = new MotorLED("/dev/gpiochip0", 20, 21);
        motor = motorled;
    }

    void TearDown() override {
        delete motorled;
    }
};

TEST_F(MotorLEDTest, MotorMovesForward) {
    motor->forward();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::FORWARD);
    sleep(2);
}

TEST_F(MotorLEDTest, MotorMovesBackward) {
    motor->backward();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::BACKWARD);
    sleep(2);
}

TEST_F(MotorLEDTest, MotorStops) {
    motor->stop();
    EXPECT_EQ(motor->get_direction(), Motor::Direction::IDLE);
    sleep(2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include "../src/door/motorLED.h"
#include "../src/door/output-switch-gpio.h"
#include <gtest/gtest.h>
#include <unistd.h>

class MotorLEDTest : public ::testing::Test {
protected:
    OutputSwitchGPIO* forward_switch;
    OutputSwitchGPIO* backward_switch;
    MotorLED* motorled;
    Motor* motor;

    void SetUp() override {
        forward_switch = new OutputSwitchGPIO("/dev/gpiochip0", 20);
        backward_switch = new OutputSwitchGPIO("/dev/gpiochip0", 21);
        motorled = new MotorLED(*forward_switch, *backward_switch);
        motor = motorled;
    }

    void TearDown() override {
        delete motorled;
        delete forward_switch;
        delete backward_switch;
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

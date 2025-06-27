#include "../src/door/input-switch-gpio.h"
#include "../src/door/output-switch-gpio.h"
#include <gtest/gtest.h>
#include <unistd.h>


class InputOutputSwitchGPIOTest : public ::testing::Test {
protected:
    InputSwitchGPIO* inputswitch;
    OutputSwitchGPIO* outputswitch;
    unsigned int input_line = 17;
    unsigned int output_line = 27;

    void SetUp() override {
        inputswitch = new InputSwitchGPIO("/dev/gpiochip0", &input_line);
        outputswitch = new OutputSwitchGPIO("/dev/gpiochip0", output_line);
    }

    void TearDown() override {
        delete inputswitch;
        delete outputswitch;
    }
};

TEST_F(InputOutputSwitchGPIOTest, InputDetectsHighFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_HIGH);
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_HIGH);
}

TEST_F(InputOutputSwitchGPIOTest, InputDetectsNotLowFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_LOW);
    EXPECT_NE(inputswitch->get_state(), InputSwitch::State::INPUT_HIGH);
}

TEST_F(InputOutputSwitchGPIOTest, InputDetectsLowFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_LOW);
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_LOW);
}

TEST_F(InputOutputSwitchGPIOTest, InputDetectsNotHighFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_HIGH);
    EXPECT_NE(inputswitch->get_state(), InputSwitch::State::INPUT_LOW);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}   
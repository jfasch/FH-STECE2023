#include <door/input-switch-gpio-sysfs.h>
#include <door/output-switch-gpio-sysfs.h>
#include <gtest/gtest.h>
#include <unistd.h>

class InputOutputSwitchGPIOSysfsTest : public ::testing::Test {
protected:
    InputSwitchGPIOSysfs* inputswitch;
    OutputSwitchGPIO* outputswitch;
/*
When using the legacy Sysfs interface, it is necessary to use the Global Pin Number (Base + Offset) 
instead of the simple BCM pin offset (like 17 or 27) for the kernel to recognize the pin correctly.
*/  
    unsigned int input_line = 529;
    unsigned int output_line = 539;

    void SetUp() override {
        inputswitch = new InputSwitchGPIOSysfs(input_line);
        outputswitch = new OutputSwitchGPIO(output_line);
        usleep(100000); 
    }

    void TearDown() override {
        delete inputswitch;
        delete outputswitch;
    }
};

TEST_F(InputOutputSwitchGPIOSysfsTest, InputDetectsHighFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_HIGH);
    usleep(50000);
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_HIGH);
}

TEST_F(InputOutputSwitchGPIOSysfsTest, InputDetectsLowFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_LOW);
    usleep(50000);
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_LOW);
}

TEST_F(InputOutputSwitchGPIOSysfsTest, InputDetectsNotLowFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_HIGH);
    usleep(50000);
    EXPECT_NE(inputswitch->get_state(), InputSwitch::State::INPUT_LOW);
}

TEST_F(InputOutputSwitchGPIOSysfsTest, InputDetectsNotHighFromOutput) {
    outputswitch->set_state(OutputSwitch::State::OUTPUT_LOW);
    usleep(50000);
    EXPECT_NE(inputswitch->get_state(), InputSwitch::State::INPUT_HIGH);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

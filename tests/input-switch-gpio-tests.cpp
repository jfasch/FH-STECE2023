#include "../src/door/input-switch-gpio.h"
#include <gtest/gtest.h>
#include <unistd.h>  

class InputSwitchGPIOTest : public ::testing::Test {
protected:
    InputSwitchGPIO* inputswitch;

    void SetUp() override {
        unsigned int line_number = 17;

        inputswitch = new InputSwitchGPIO("/dev/gpiochip0", &line_number);
    }

    void TearDown() override {
        delete inputswitch;
    }
};

TEST_F(InputSwitchGPIOTest, BeamIsSolidWhenNotBlocked) {
    // Manually ensure the beam is not blocked 
    printf("Press Enter to simulate beam is solid(=1) ...\n");
    getchar(); // Wait for user input to proceed
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_HIGH);
    
    
}

TEST_F(InputSwitchGPIOTest, BeamIsBrokenWhenBlocked) {
    // Manually block the beam 
    printf("Press Enter to simulate beam is broken(=0) ...\n");
    getchar(); // Wait for user input to proceed
    EXPECT_EQ(inputswitch->get_state(), InputSwitch::State::INPUT_LOW);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

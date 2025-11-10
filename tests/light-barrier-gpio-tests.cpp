#include "../src/door/input-switch-gpio.h"
#include <gtest/gtest.h>
#include <unistd.h>  

class LightBarrierGPIOTest : public ::testing::Test {
protected:
    InputSwitchGPIO* lightbarrier;

    void SetUp() override {
        unsigned int line_number = 17;

        lightbarrier = new InputSwitchGPIO("/dev/gpiochip0", &line_number);
    }

    void TearDown() override {
        delete lightbarrier;
    }
};

TEST_F(LightBarrierGPIOTest, BeamIsSolidWhenNotBlocked) {
    // Manually ensure the beam is not blocked 
    printf("Press Enter to simulate beam is solid(=1) ...\n");
    getchar(); // Wait for user input to proceed
    EXPECT_EQ(lightbarrier->get_state(), InputSwitch::State::INPUT_HIGH);
    
    
}

TEST_F(LightBarrierGPIOTest, BeamIsBrokenWhenBlocked) {
    // Manually block the beam 
    printf("Press Enter to simulate beam is broken(=0) ...\n");
    getchar(); // Wait for user input to proceed
    EXPECT_EQ(lightbarrier->get_state(), InputSwitch::State::INPUT_LOW);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

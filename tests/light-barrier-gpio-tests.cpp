#include "../src/door/light-barrier-gpio.h"
#include <gtest/gtest.h>
#include <unistd.h>  

class LightBarrierGPIOTest : public ::testing::Test {
protected:
    LightBarrierGPIO* lightbarrier;

    void SetUp() override {

        lightbarrier = new LightBarrierGPIO("/dev/gpiochip0", 17);
    }

    void TearDown() override {
        delete lightbarrier;
    }
};

TEST_F(LightBarrierGPIOTest, BeamIsSolidWhenNotBlocked) {
    // Manually ensure the beam is not blocked 
    EXPECT_EQ(lightbarrier->get_state(), LightBarrier::State::BEAM_SOLID);
    sleep(2);
}

TEST_F(LightBarrierGPIOTest, BeamIsBrokenWhenBlocked) {
    // Manually block the beam 
    sleep(2); 
    EXPECT_EQ(lightbarrier->get_state(), LightBarrier::State::BEAM_BROKEN);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

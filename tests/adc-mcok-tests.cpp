#include <gtest/gtest.h>
#include <door/adc-mock.h>

TEST(Adc_mock_suite, Adc_test)
{
    MockAdc adc;

    adc.set_value(3.3f);

    ASSERT_NEAR(adc.get_value(), 3.3f, 0.001);

};

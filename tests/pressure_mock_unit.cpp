#include <gtest/gtest.h>
#include <door/pressure-sensor-mock.h>

TEST(Pressure_read_suite, Pressure_sensor_test)
{

    PressureSensorMock PressureSensor;

    PressureSensor.set_pressure(25.12);

    ASSERT_NEAR(PressureSensor.get_pressure(),25.12,0.001);

};
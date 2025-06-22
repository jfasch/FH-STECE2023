#include <gtest/gtest.h>
#include <door/pressure-sensor-bmp280.h>

TEST(Pressure_read_suite, Pressure_sensor_test)
{

    BMP280 bmp280;

    ASSERT_NEAR(bmp280.get_pressure(),1000,100);

};


#include "UnitTest++.h"
#include <door/push-button-mock.h>

TEST(Pressure_read_test)
{

    PressureMock Pressure_sensor(Pressure::xy);

    CHECK_EQUAL(Pressure_sensor.read(), Pressure:xy);

};

//
#include <gtest/gtest.h>
#include <door/pressure-sensor-mock.h>
#include <door/pressure-sensor-event-generator.h>

TEST(Pressure_read_suite, Pressure_sensor_test)
{

    PressureSensorMock PressureSensor;

    PressureSensor.set_pressure(25.12);

    ASSERT_NEAR(PressureSensor.get_pressure(),25.12,0.001);

};

TEST(Pressure_read_suite, Pressure_sensor_event_generator_test)
{
    PressureSensorMock PressureSensor;
    PressureSensor.set_pressure(25.12);

    PressureSensorEventGenerator event_generator(&PressureSensor, 20.0f, 30.0f);
    
    ASSERT_EQ(event_generator.get_event(), PressuerSensorEvent::NORMAL_PRESSURE);

    PressureSensor.set_pressure(15.56f);
    ASSERT_EQ(event_generator.get_event(), PressuerSensorEvent::UNDER_PRESSURE);

    PressureSensor.set_pressure(35.0f);
    ASSERT_EQ(event_generator.get_event(), PressuerSensorEvent::OVER_PRESSURE);

    PressureSensor.set_pressure(-5.0f);
    ASSERT_EQ(event_generator.get_event(), PressuerSensorEvent::PRESSURE_SENSOR_ERROR);
}
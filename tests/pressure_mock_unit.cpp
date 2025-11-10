#include <gtest/gtest.h>
#include <door/pressure-sensor-mock.h>
#include <door/pressure-sensor-event-generator.h>

TEST(Pressure_read_suite, Pressure_sensor_init_test)
{

    PressureSensorMock PressureSensor;

    ASSERT_NEAR(PressureSensor.get_pressure(),0.0f,0.001);

};

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
    
    ASSERT_EQ(event_generator.get_event(), PressureSensorEvent::NORMAL_PRESSURE);

    PressureSensor.set_pressure(15.56f);
    ASSERT_EQ(event_generator.get_event(), PressureSensorEvent::UNDER_PRESSURE);

    PressureSensor.set_pressure(35.0f);
    ASSERT_EQ(event_generator.get_event(), PressureSensorEvent::OVER_PRESSURE);

    PressureSensor.set_pressure(-5.0f);
    ASSERT_EQ(event_generator.get_event(), PressureSensorEvent::PRESSURE_SENSOR_ERROR);
}

TEST(Pressure_read_suite, Pressure_sensor_event_generator_hysteresis_test)
{
    PressureSensorMock mock;
    // thresholds
    float under = 1.0f;
    float over = 3.0f;

    // enable hysteresis with margin 0.2
    PressureSensorEventGenerator gen(&mock, under, over, true, 0.2f);

    // start in normal
    mock.set_pressure(2.0f);
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::NORMAL_PRESSURE);

    // small rise below hysteresis margin -> stay NORMAL
    mock.set_pressure(3.05f); // over + h = 3.2 -> should remain NORMAL
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::NORMAL_PRESSURE);

    // exceed hysteresis margin -> become OVER
    mock.set_pressure(3.25f);
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::OVER_PRESSURE);

    // small drop but still above over - h -> remain OVER
    mock.set_pressure(3.1f); // over - h = 2.8 -> still OVER
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::OVER_PRESSURE);

    // drop below over - h -> back to NORMAL
    mock.set_pressure(2.75f);
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::NORMAL_PRESSURE);

    // test under hysteresis
    mock.set_pressure(0.95f); // under - h = 0.8 -> 0.95 > 0.8 so should remain NORMAL
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::NORMAL_PRESSURE);

    // drop below under - h -> become UNDER
    mock.set_pressure(0.75f);
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::UNDER_PRESSURE);

    // recover above under + h -> become NORMAL
    mock.set_pressure(1.25f); // under + h = 1.2
    ASSERT_EQ(gen.get_event(), PressureSensorEvent::NORMAL_PRESSURE);
}
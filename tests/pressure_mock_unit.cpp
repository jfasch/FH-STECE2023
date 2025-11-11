#include <gtest/gtest.h>
#include <door/analog-sensor-mock.h>
#include <door/analog-sensor-event-generator.h>

TEST(Pressure_read_suite, Pressure_sensor_test)
{

    AnalogSensorMock PressureSensor;

    PressureSensor.set_value(25.12);

    ASSERT_NEAR(PressureSensor.get_value(),25.12,0.001);

};

TEST(Pressure_read_suite, Pressure_sensor_event_generator_test)
{
    AnalogSensorMock PressureSensor;
    PressureSensor.set_value(25.12);

    AnalogSensorEventGenerator event_generator(&PressureSensor, 20.0f, 30.0f);
    
    ASSERT_EQ(event_generator.get_event(), AnalogSensorEvent::NORMAL_VALUE);

    PressureSensor.set_value(15.56f);
    ASSERT_EQ(event_generator.get_event(), AnalogSensorEvent::UNDER_VALUE);

    PressureSensor.set_value(35.0f);
    ASSERT_EQ(event_generator.get_event(), AnalogSensorEvent::OVER_VALUE);

    PressureSensor.set_value(-5.0f);
    ASSERT_EQ(event_generator.get_event(), AnalogSensorEvent::ANALOG_SENSOR_ERROR);
}

TEST(Pressure_read_suite, Pressure_sensor_event_generator_hysteresis_test)
{
    AnalogSensorMock mock;
    // thresholds
    float under = 1.0f;
    float over = 3.0f;

    // enable hysteresis with margin 0.2
    AnalogSensorEventGenerator gen(&mock, under, over, true, 0.2f);

    // start in normal
    mock.set_value(2.0f);
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::NORMAL_VALUE);

    // small rise below hysteresis margin -> stay NORMAL
    mock.set_value(3.05f); // over + h = 3.2 -> should remain NORMAL
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::NORMAL_VALUE);

    // exceed hysteresis margin -> become OVER
    mock.set_value(3.25f);
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::OVER_VALUE);

    // small drop but still above over - h -> remain OVER
    mock.set_value(3.1f); // over - h = 2.8 -> still OVER
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::OVER_VALUE);

    // drop below over - h -> back to NORMAL
    mock.set_value(2.75f);
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::NORMAL_VALUE);

    // test under hysteresis
    mock.set_value(0.95f); // under - h = 0.8 -> 0.95 > 0.8 so should remain NORMAL
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::NORMAL_VALUE);

    // drop below under - h -> become UNDER
    mock.set_value(0.75f);
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::UNDER_VALUE);

    // recover above under + h -> become NORMAL
    mock.set_value(1.25f); // under + h = 1.2
    ASSERT_EQ(gen.get_event(), AnalogSensorEvent::NORMAL_VALUE);
}
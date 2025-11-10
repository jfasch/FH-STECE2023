#include <door/door.h>
#include <gtest/gtest.h>
#include <stdbool.h>
#include <door/inputs.h>
#include <door/event-edge-detector.h>
#include <door/input-switch-mock.h>
#include <door/inputs.h>
#include <door/pressure-sensor.h>
#include <door/pressure-sensor-mock.h>
#include <door/pressure-sensor-event-generator.h>






TEST(input_suite, input_init)
{
    
    InputSwitchMock do_close(InputSwitch::State::INPUT_LOW);
    InputSwitchMock do_open(InputSwitch::State::INPUT_LOW);
    InputSwitchMock closed_position(InputSwitch::State::INPUT_LOW);    // door in "closed" position
    InputSwitchMock opened_position(InputSwitch::State::INPUT_HIGH);   // door not in "opened" position
    PressureSensorMock pressureSensor;
    PressureSensorEventGenerator pressureSensorEG(&pressureSensor);

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, &pressureSensorEG, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(inputs.button_inside, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.button_outside, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_opened, InputSwitch::State::INPUT_HIGH);
}

TEST(input_suite, input_switch)
{
    
    InputSwitchMock do_close(InputSwitch::State::INPUT_LOW);
    InputSwitchMock do_open(InputSwitch::State::INPUT_LOW);
    InputSwitchMock closed_position(InputSwitch::State::INPUT_LOW);    // door in "closed" position
    InputSwitchMock opened_position(InputSwitch::State::INPUT_HIGH);   // door not in "opened" position
    PressureSensorMock pressureSensor;
    PressureSensorEventGenerator pressureSensorEG(&pressureSensor);

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, &pressureSensorEG, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(inputs.button_inside, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.button_outside, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_opened, InputSwitch::State::INPUT_HIGH);

    do_close.set_state(InputSwitch::State::INPUT_HIGH);
    do_open.set_state(InputSwitch::State::INPUT_LOW);
    closed_position.set_state(InputSwitch::State::INPUT_HIGH);
    opened_position.set_state(InputSwitch::State::INPUT_LOW);

    inputs = inputs_set.get_inputs();

    // check state and output
    ASSERT_EQ(inputs.button_inside, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.button_outside, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_opened, InputSwitch::State::INPUT_LOW);
}

TEST(input_suite, event_init)
{
    
    InputSwitchMock do_close(InputSwitch::State::INPUT_LOW);
    InputSwitchMock do_open(InputSwitch::State::INPUT_LOW);
    InputSwitchMock closed_position(InputSwitch::State::INPUT_LOW);    // door in "closed" position
    InputSwitchMock opened_position(InputSwitch::State::INPUT_HIGH);   // door not in "opened" position
    PressureSensorMock pressureSensor;
    PressureSensorEventGenerator pressureSensorEG(&pressureSensor);

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, &pressureSensorEG, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(events.close_button_pressed, EdgeDetector::NONE);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::NONE);
    //ASSERT_EQ(events.light_barrier_1_reached, EdgeDetector::RISING);
    //ASSERT_EQ(events.light_barrier_2_reached, EdgeDetector::RISING);
}

TEST(input_suite, event_switch)
{
    
    InputSwitchMock do_close(InputSwitch::State::INPUT_LOW);
    InputSwitchMock do_open(InputSwitch::State::INPUT_LOW);
    InputSwitchMock closed_position(InputSwitch::State::INPUT_LOW);  // door in "closed" position
    InputSwitchMock opened_position(InputSwitch::State::INPUT_HIGH); // door not in "opened" position
    PressureSensorMock pressureSensor;
    PressureSensorEventGenerator pressureSensorEG(&pressureSensor);

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, &pressureSensorEG, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(events.close_button_pressed, EdgeDetector::NONE);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::NONE);

    do_close.set_state(InputSwitch::State::INPUT_HIGH);
    do_open.set_state(InputSwitch::State::INPUT_HIGH);

    events = inputs_set.get_events();

    ASSERT_EQ(events.close_button_pressed, EdgeDetector::RISING);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::RISING);

    events = inputs_set.get_events();

    ASSERT_EQ(events.close_button_pressed, EdgeDetector::NONE);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::NONE);

    //ASSERT_EQ(events.light_barrier_1_reached, EdgeDetector::RISING);
    //ASSERT_EQ(events.light_barrier_2_reached, EdgeDetector::RISING);
}

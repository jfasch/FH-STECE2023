#include <door/door.h>
#include <door/input-switch.h>
#include <gtest/gtest.h>
#include <stdbool.h>
#include <stdlib.h>

// Transition from "OPENED" to "CLOSING" with button_outside
TEST(door_suite, door_closing_button_outside_pressed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENED);

    // create events struct
    events_t events;
    events.analog_state = AnalogSensorEvent::NORMAL_VALUE;
    events.button_outside_pressed = EdgeDetector::RISING;
    events.button_inside_pressed = EdgeDetector::NONE;
    events.light_barrier_closed = EdgeDetector::NONE;
    events.light_barrier_open = EdgeDetector::NONE;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // button change is none
    events.button_outside_pressed = EdgeDetector::NONE;

    // call door again
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
}

// Transition from "OPENED" to "CLOSING" with button_inside
TEST(door_suite, door_closing_button_inside_pressed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENED);

    // create events struct
    events_t events;
    events.analog_state = AnalogSensorEvent::NORMAL_VALUE;
    events.button_outside_pressed = EdgeDetector::NONE;
    events.button_inside_pressed = EdgeDetector::RISING;
    events.light_barrier_closed = EdgeDetector::NONE;
    events.light_barrier_open = EdgeDetector::NONE;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // button change is none
    events.button_inside_pressed = EdgeDetector::NONE;

    // call door again
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
}

// Transition from "CLOSING" to "CLOSED"
TEST(door_suite, door_closed_reached)
{
    //create Door object
    Door door;
    door.set_state(Door::State::CLOSING);

    // create events struct
    events_t events;
    events.analog_state = AnalogSensorEvent::NORMAL_VALUE;
    events.button_inside_pressed = EdgeDetector::NONE;
    events.button_outside_pressed = EdgeDetector::NONE;
    events.light_barrier_closed = EdgeDetector::FALLING;
    events.light_barrier_open = EdgeDetector::NONE;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);

    // run again
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

// Error states during "CLOSING"
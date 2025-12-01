#include <door/door.h>
#include <door/input-switch.h>
#include <gtest/gtest.h>
#include <stdbool.h>
#include <stdlib.h>


// TODO: Replace in test "door_cyclic_opened_to_closing" button to timer

TEST(door_suite, door_init)
{
    // create Door object
    Door door;

    // create Input struct
    input_t input;
    // Assumption -> limit switches are active low
    input.sensor_closed = InputSwitch::State::INPUT_LOW;
    input.sensor_open = InputSwitch::State::INPUT_HIGH;

    // create Output struct
    output_t output;

    // run door.init
    output = door.init(input);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

TEST(door_suite, door_init_error)
{
    // create Door object
    Door door;

    // create Input struct
    input_t input;
    // Assumption -> limit switches are active low
    input.sensor_closed = InputSwitch::State::INPUT_HIGH;
    input.sensor_open = InputSwitch::State::INPUT_HIGH;

    // create Output struct
    output_t output;

    // run door.init
    output = door.init(input);

    // check state
    ASSERT_EQ(door.get_state(), Door::State::ERROR_MIDDLE_POSITION);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

TEST(door_suite, door_button_outside_pressed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events struct
    events_t events;
    events.button_outside_pressed = EdgeDetector::RISING;
    events.button_inside_pressed = EdgeDetector::NONE;
    events.light_barrier_closed = EdgeDetector::NONE;
    events.light_barrier_open = EdgeDetector::NONE;
    events.analog_state = AnalogSensorEvent::NORMAL_VALUE;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // button change is none
    events.button_outside_pressed = EdgeDetector::NONE;

    // call again
    output = door.cyclic(events);

    // checks
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);
}

TEST(door_suite, door_cyclic_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::INIT);

    // create events struct
    events_t events;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}




// --- CLOSED TO OPENING TESTS ---

TEST(door_suite, door_cyclic_closed_to_opening)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // Test button inside
    events.button_inside_pressed = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // Test button outside
    door.set_state(Door::State::CLOSED);
    events.button_outside_pressed = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);
}

// --- OPENING ERROR TESTS ---

TEST(door_suite, door_cyclic_opening_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENING);

    // create events and input struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // Error - Motor idle
    output.motor_direction = Motor::Direction::IDLE;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);


    // Error - Motor running backward
    door.set_state(Door::State::OPENING);

    output.motor_direction = Motor::Direction::BACKWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // Error - Lighbarrier, both aktive
    door.set_state(Door::State::OPENING);

    inputs.sensor_closed = InputSwitch::State::INPUT_LOW;
    inputs.sensor_open = InputSwitch::State::INPUT_LOW;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

}

// --- OPENING TO OPEN TEST ---

TEST(door_suite, door_cyclic_opening_to_open)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENING);

    // create events struct
    events_t events;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // generates a random error
    //int state = rand();

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);

    events.light_barrier_open = EdgeDetector::FALLING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

// --- OPENED ERROR TESTS ---

TEST(door_suite, door_cyclic_opened_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENED);

    // create events and input struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_LOW);

    // Error - Motor running forward
    output.motor_direction = Motor::Direction::FORWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);


    // Error - Motor running backward
    door.set_state(Door::State::OPENED);

    output.motor_direction = Motor::Direction::BACKWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // Error - Lighbarrier, both aktive
    door.set_state(Door::State::OPENED);

    inputs.sensor_closed = InputSwitch::State::INPUT_LOW;
    inputs.sensor_open = InputSwitch::State::INPUT_LOW;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

}

// --- OPENED TO CLOSING TEST ---

TEST(door_suite, door_cyclic_opened_to_closing)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENED);

    // create events struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_LOW);

    // closing event is currently triggered via buttons
    // Test button inside
    events.button_inside_pressed = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // Test button outside
    door.set_state(Door::State::OPENED);
    events.button_outside_pressed = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

        // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

}

// --- CLOSING ERROR TESTS ---

TEST(door_suite, door_cyclic_closing_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSING);

    // create events and input struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // generates a random error
    //int state = rand();

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // Error - Motor idle
    output.motor_direction = Motor::Direction::IDLE;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);


    // Error - Motor running forward
    door.set_state(Door::State::CLOSING);

    output.motor_direction = Motor::Direction::FORWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // Error - Lighbarrier, both aktive
    door.set_state(Door::State::CLOSING);

    inputs.sensor_closed = InputSwitch::State::INPUT_LOW;
    inputs.sensor_open = InputSwitch::State::INPUT_LOW;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

}

// --- CLOSING TO CLOSED TEST ---

TEST(door_suite, door_cyclic_closing_to_closed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSING);

    // create events struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);

    // set events
    events.light_barrier_closed = EdgeDetector::FALLING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_LOW);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);
}

// --- CLOSED ERROR TESTS ---

TEST(door_suite, door_cyclic_closed_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events and input struct
    events_t events;
    input_t inputs;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // generates a random error
    //int state = rand();

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_LOW);

    // Error - Motor running forward
    output.motor_direction = Motor::Direction::FORWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);


    // Error - Motor running backward
    door.set_state(Door::State::CLOSED);

    output.motor_direction = Motor::Direction::BACKWARD;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // Error - Lighbarrier, both aktive
    door.set_state(Door::State::CLOSED);

    inputs.sensor_closed = InputSwitch::State::INPUT_LOW;
    inputs.sensor_open = InputSwitch::State::INPUT_LOW;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

}


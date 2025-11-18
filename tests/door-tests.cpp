#include <door/door.h>
#include <door/input-switch.h>
#include <gtest/gtest.h>
#include <stdbool.h>
#include <stdlib.h>

TEST(door_suite, door_init)
{
    // create Door object
    Door door;

    // create Input struct
    input_t input;
    input.sensor_closed = InputSwitch::State::INPUT_LOW;

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

    // create Output struct
    output_t output;

    // run door.init
    output = door.init(input);

    // check state
    ASSERT_EQ(door.get_state(), Door::State::ERROR_MIDDLE_POSITION);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

TEST(door_suite, door_cyclic)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events struct
    events_t events;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

TEST(door_suite, door_cyclic_open_button_pressed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events struct
    events_t events;
    events.button_inside_pressed = EdgeDetector::RISING;
    events.button_outside_pressed = EdgeDetector::RISING;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
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

// --- OPENING TESTS ---
// check outputs
TEST(door_suite, door_cyclic_opening)
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

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::FORWARD);
}

TEST(door_suite, door_cyclic_opening_error)
{
    // create Door object
    Door door;
    door.set_state(Door::State::OPENING);

    // create events struct
    events_t events;

    // create output struct
    output_t output;

    // set motor in wrong mode
    output.motor_direction = Motor::Direction::IDLE;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::ERROR_SOMETHING_BADLY_WRONG);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);

    // set motor in wrong direction
    output.motor_direction = Motor::Direction::BACKWARD;

    door.set_state(Door::State::OPENING);

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

    events.light_barrier_open = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
}

// --- OPENED TESTS ---

TEST(door_suite, door_cyclic_opened)
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

    // generates a random error
    //int state = rand();

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENED);
    ASSERT_EQ(output.motor_direction, Motor::Direction::IDLE);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_LOW);

}

// --- OPEN TO CLOSING TEST ---

TEST(door_suite, door_cyclic_open_to_closing)
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

    // set events
    events.button_inside_pressed = EdgeDetector::RISING;
    events.button_outside_pressed = EdgeDetector::RISING;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSING);
    ASSERT_EQ(output.motor_direction, Motor::Direction::BACKWARD);
    ASSERT_EQ(inputs.sensor_closed, InputSwitch::State::INPUT_HIGH);
    ASSERT_EQ(inputs.sensor_open, InputSwitch::State::INPUT_HIGH);
}

/*
TEST(door_suite, straightforward_open)
{
    Door door();
    Events events();

    door.check(const Events& events);

    ASSERT_EQ(door.get_state(), Door::State::CLOSED);

    
    // build a door and its parts
    MotorMock motor(Motor::Direction::IDLE);
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position

    Door door(&motor, &do_close, &do_open, &closed_position, &opened_position);

    door.check();
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);              // <-- inferred from the light barrier situation

    // all idle: no button pressed -> motor must remain idle at
    // check()
    door.check();
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PushButton::State::PRESSED);
    door.check();    
    ASSERT_EQ(motor.get_direction(), Motor::Direction::FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    opened_position.set_state(LightBarrier::State::BEAM_BROKEN);
    closed_position.set_state(LightBarrier::State::BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                   //     if one beam is broken, the other must be solid, 
                                                                   //     and vice versa
    door.check();
    EXPECT_EQ(motor.get_direction(), Motor::Direction::IDLE);
}
*/

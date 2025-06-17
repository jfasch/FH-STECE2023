#include <door/door.h>
#include <gtest/gtest.h>
#include <stdbool.h>

TEST(door_suite, door_init)
{
    // create Door object
    Door door;

    // create Input struct
    input_t input;
    input.sensor_closed = true;

    // create Output struct
    output_t output;

    // run door.init
    output = door.init(input);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::CLOSED);
    ASSERT_EQ(output.motor_left, false);
    ASSERT_EQ(output.motor_right, false);
    ASSERT_EQ(output.display, false);
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
    ASSERT_EQ(output.motor_left, false);
    ASSERT_EQ(output.motor_right, false);
    ASSERT_EQ(output.display, false);
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
    ASSERT_EQ(output.motor_left, false);
    ASSERT_EQ(output.motor_right, false);
    ASSERT_EQ(output.display, false);
}

TEST(door_suite, door_cyclic_open_button_pressed)
{
    // create Door object
    Door door;
    door.set_state(Door::State::CLOSED);

    // create events struct
    events_t events;
    events.open_button_pressed = true;

    // create output struct
    output_t output;

    // run door.cyclic
    output = door.cyclic(events);

    // check state and output
    ASSERT_EQ(door.get_state(), Door::State::OPENING);
    ASSERT_EQ(output.motor_left, false);
    ASSERT_EQ(output.motor_right, false);
    ASSERT_EQ(output.display, false);
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
    ASSERT_EQ(output.motor_left, false);
    ASSERT_EQ(output.motor_right, false);
    ASSERT_EQ(output.display, false);
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
    ASSERT_EQ(motor.get_direction(), Motor::Direction::IDLE);
    
}
*/
#include <door/door.h>
#include <gtest/gtest.h>
#include <stdbool.h>
#include <door/inputs.h>
#include <door/event-edge-detector.h>
#include <door/push-button-mock.h>
#include <door/light-barrier-mock.h>

TEST(input_suite, input_init)
{
    
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position
    

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(inputs.button_inside, PushButton::State::RELEASED);
    ASSERT_EQ(inputs.button_outside, PushButton::State::RELEASED);
    ASSERT_EQ(inputs.sensor_closed, LightBarrier::State::BEAM_BROKEN);
    ASSERT_EQ(inputs.sensor_opened, LightBarrier::State::BEAM_SOLID);
}

TEST(input_suite, input_switch)
{
    
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position
    

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(inputs.button_inside, PushButton::State::RELEASED);
    ASSERT_EQ(inputs.button_outside, PushButton::State::RELEASED);
    ASSERT_EQ(inputs.sensor_closed, LightBarrier::State::BEAM_BROKEN);
    ASSERT_EQ(inputs.sensor_opened, LightBarrier::State::BEAM_SOLID);

    do_close.set_state(PushButton::State::PRESSED);
    do_open.set_state(PushButton::State::RELEASED);
    closed_position.set_state(LightBarrier::State::BEAM_SOLID);
    opened_position.set_state(LightBarrier::State::BEAM_BROKEN);

    inputs = inputs_set.get_inputs();

    // check state and output
    ASSERT_EQ(inputs.button_inside, PushButton::State::PRESSED);
    ASSERT_EQ(inputs.button_outside, PushButton::State::RELEASED);
    ASSERT_EQ(inputs.sensor_closed, LightBarrier::State::BEAM_SOLID);
    ASSERT_EQ(inputs.sensor_opened, LightBarrier::State::BEAM_BROKEN);
}

TEST(input_suite, event_init)
{
    
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position
    

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, time);

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
    
    PushButtonMock do_close(PushButton::State::RELEASED);
    PushButtonMock do_open(PushButton::State::RELEASED);
    LightBarrierMock closed_position(LightBarrier::State::BEAM_BROKEN);  // <-- door in "closed" position
    LightBarrierMock opened_position(LightBarrier::State::BEAM_SOLID);   // <-- door not in "opened" position
    

    // create Input struct
    TimeSpec time;
    Inputs inputs_set(&do_close, &do_open, &closed_position, &opened_position, time);

    input_t inputs;
    events_t events;

    inputs = inputs_set.get_inputs();
    events = inputs_set.get_events();


    // check state and output
    ASSERT_EQ(events.close_button_pressed, EdgeDetector::NONE);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::NONE);

    do_close.set_state(PushButton::State::PRESSED);
    do_open.set_state(PushButton::State::PRESSED);

    events = inputs_set.get_events();

    ASSERT_EQ(events.close_button_pressed, EdgeDetector::RISING);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::RISING);

    events = inputs_set.get_events();

    ASSERT_EQ(events.close_button_pressed, EdgeDetector::NONE);
    ASSERT_EQ(events.open_button_pressed, EdgeDetector::NONE);

    //ASSERT_EQ(events.light_barrier_1_reached, EdgeDetector::RISING);
    //ASSERT_EQ(events.light_barrier_2_reached, EdgeDetector::RISING);
}
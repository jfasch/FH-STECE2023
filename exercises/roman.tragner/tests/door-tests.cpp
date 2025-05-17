#include <gtest/gtest.h>

#include <door.h>


TEST(door_suite, straightforward_open)
{
    // build a door and its parts
    Motor motor(MotorDirection::IDLE);

    PushButton do_close(PUSHBUTTON_RELEASED);
   
    PushButton do_open(PUSHBUTTON_RELEASED);
   

    LightBarrier closed_position(LightBarrierState::BEAM_BROKEN);


    LightBarrier opened_position(LightBarrierState::BEAM_SOLID);
   
    Door door(&door, &motor, &do_close, &do_open, &closed_position, &opened_position);


    Door.check();
    ASSERT_EQ(door.getState(), DoorState::CLOSED); 

    // all idle: no button pressed -> motor must remain idle at
    // check()

    door.check();
    ASSERT_EQ(door.getDirection(), DoorState::IDLE); 

    // "open" button pressed -> motor direction must be set to
    // "opening"
    do_open.set_state(PUSHBUTTON_PRESSED);
    door.check();
      
    ASSERT_EQ(motor.getDirection(), MotorDirection::FORWARD);

    // "opened" position reached (light barrier's beam broken) ->
    // motor stopped
    
    
    opened_position.set_state(LightBarrierState::BEAM_BROKEN);
    closed_position.set_state(LightBarrierState::BEAM_SOLID);    // <-- should probably be verified by door logic: 
                                                                          //     if one beam is broken, the other must be solid, 
                                                                          //     and vice versa
    door.check();
    ASSERT_EQ(motor.getDirection(), MotorDirection:IDLE);
}

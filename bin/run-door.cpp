#include <door/door.h>
#include <door/structs.h>
#include <door/inputs.h>
#include <door/outputs.h>
#include <door/motor-mock.h>
#include <door/input-switch-mock.h>
#include <door/timespec.h>

#include <iostream>


int main()
{
    std::cout << "howdy" << std::endl;

    Door door;

    InputSwitchMock button1(InputSwitch::State::INPUT_LOW);
    InputSwitchMock button2(InputSwitch::State::INPUT_LOW);
    InputSwitchMock light1(InputSwitch::State::INPUT_LOW);
    InputSwitchMock light2(InputSwitch::State::INPUT_HIGH);
    MotorMock motor(Motor::Direction::IDLE);

    TimeSpec time;

    Inputs inputs(&button1, &button2, &light1, &light2, time);
    Outputs outputs(&motor);

    input_t in;
    events_t ev;
    output_t out;
    
    // get current inputs and create input struct
    in = inputs.get_inputs();

    // run door init and return output struct
    out = door.init(in);

    // set outputs
    outputs.set_outputs(out);

    // --- run main SPS loop
    auto interval = TimeSpec::from_milliseconds(1);

    while (true) {

        // get current events and create event struct
        ev = inputs.get_events();

        // call door logic, and complain about cycle-time violation
        auto before = TimeSpec::now_monotonic();

        // run door cyclic and return output struct
        out = door.cyclic(ev);

        auto after = TimeSpec::now_monotonic();

        auto spent = after - before;
        if (spent > interval)
            std::cerr << "WARNING: door logic exceeds interval" << std::endl;

        // set outputs
        outputs.set_outputs(out);

        // suspend for the rest of the interval
        auto suspend = interval - spent;
        nanosleep(&suspend, nullptr);
    }

    std::cerr << "bye" << std::endl;

    return 0;
}

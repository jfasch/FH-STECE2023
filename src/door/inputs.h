#pragma once
#include <door/structs.h>
#include <door/timespec.h>


class Inputs
{
public:
    Inputs(InputSwitch* button, InputSwitch* button2, InputSwitch* LightBarrier1, InputSwitch* LightBarrier2, const TimeSpec& debounce_time);
    ~Inputs();

    // void check(const Events& events);
    input_t get_inputs();
    events_t get_events();

    
private:
    InputSwitch* _button;
    InputSwitch* _button2;
    InputSwitch* _LightBarrier1;
    InputSwitch* _LightBarrier2;

    EdgeDetector *_edge_button;
    EdgeDetector *_edge_button2;
};

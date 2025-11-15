#pragma once

#include "structs.h"
#include "timespec.h"
#include "pressure-sensor-event-generator.h"


class Inputs
{
public:
    Inputs(InputSwitch* button_outside, InputSwitch* button_inside, InputSwitch* light_barrier_closed, InputSwitch* light_barrier_open, PressureSensorEventGenerator* pressuresensor, const TimeSpec& debounce_time);
    ~Inputs();

    // void check(const Events& events);
    input_t get_inputs();
    events_t get_events();

    
private:
    InputSwitch* _button_outside;
    InputSwitch* _button_inside;
    InputSwitch* _lightbarrier_closed;
    InputSwitch* _lightbarrier_open;
    PressureSensorEventGenerator* _pressuresensor;

    EdgeDetector *_edge_button;
    EdgeDetector *_edge_button2;
};

#pragma once

#include "structs.h"
#include "timespec.h"
#include "pressure-sensor-event-generator.h"


class Inputs
{
public:
    Inputs(InputSwitch* button, InputSwitch* button2, InputSwitch* LightBarrier1, InputSwitch* LightBarrier2, PressureSensorEventGenerator* pressuresensor, const TimeSpec& debounce_time);
    ~Inputs();

    // void check(const Events& events);
    input_t get_inputs();
    events_t get_events();

    
private:
    InputSwitch* _button;
    InputSwitch* _button2;
    InputSwitch* _LightBarrier1;
    InputSwitch* _LightBarrier2;
    PressureSensorEventGenerator* _pressuresensor;

    EdgeDetector *_edge_button;
    EdgeDetector *_edge_button2;
};

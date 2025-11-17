#include "inputs.h"
#include "event-edge-detector.h"
#include "analog-sensor-event-generator.h"


Inputs::Inputs(InputSwitch* button_outside, InputSwitch* button_inside, InputSwitch* lightbarrier_closed, InputSwitch* lightbarrier_open, AnalogSensorEventGenerator* analogsensor, const TimeSpec& debounce_time)
{
    _button_outside = button_outside;
    _button_inside = button_inside;
    _lightbarrier_closed = lightbarrier_closed;
    _lightbarrier_open = lightbarrier_open;
    _Analogsensor = analogsensor;

    _edge_button = new EdgeDetector(button_outside, debounce_time);
    _edge_button2 = new EdgeDetector(button_inside, debounce_time);
}

Inputs::~Inputs()
{
    delete _edge_button;
    delete _edge_button2;
}

input_t Inputs::get_inputs()
{
    input_t input;
    input.button_outside = _button_outside->get_state();
    input.button_inside = _button_inside->get_state();
    input.sensor_closed = _lightbarrier_closed->get_state();
    input.sensor_open = _lightbarrier_open->get_state();
    input.analogsensor = _Analogsensor->get_event();
    return input;

}

events_t Inputs::get_events()
{
    events_t events;
    auto now = TimeSpec::now_monotonic();
    events.close_button_pressed = _edge_button->detect_edge(now);
    events.open_button_pressed = _edge_button2->detect_edge(now);
    events.analog_state = _Analogsensor->get_event();
    return events;
}

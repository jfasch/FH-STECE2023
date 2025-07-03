#include <door/inputs.h>
#include <door/event-edge-detector.h>

Inputs::Inputs(InputSwitch* button, InputSwitch* button2, InputSwitch* LightBarrier1, InputSwitch* LightBarrier2, const TimeSpec& debounce_time)
{
    _button = button;
    _button2 = button2;
    _LightBarrier1 = LightBarrier1;
    _LightBarrier2 = LightBarrier2;

    _edge_button = new EdgeDetector(button, debounce_time);
    _edge_button2 = new EdgeDetector(button2, debounce_time);
}

Inputs::~Inputs()
{
    delete _edge_button;
    delete _edge_button2;
}

input_t Inputs::get_inputs()
{
    input_t input;
    input.button_inside = _button->get_state();
    input.button_outside = _button2->get_state();
    input.sensor_closed = _LightBarrier1->get_state();
    input.sensor_opened = _LightBarrier2->get_state();
    return input;

}

events_t Inputs::get_events()
{
    events_t events;
    auto now = TimeSpec::now_monotonic();
    events.close_button_pressed = _edge_button->detect_edge(now);
    events.open_button_pressed = _edge_button2->detect_edge(now);
    return events;
}

#include <door/inputs.h>
#include <door/event-edge-detector.h>

Inputs::Inputs(PushButton* button, PushButton* button2, LightBarrier* lightbarrier, LightBarrier* lightbarrier2)
{
    _button = button;
    _button2 = button2;
    _lightbarrier = lightbarrier;
    _lightbarrier2 = lightbarrier2;

    _edge_button = new EdgeDetector(button);
    _edge_button2 = new EdgeDetector(button2);
    //EdgeDetector _edge_lightbarrier(lightbarrier);
    //EdgeDetector _edge_lightbarrier2(lightbarrier2);

}

Inputs::~Inputs()
{
    delete _edge_button;
    delete _edge_button2;
}

input_t Inputs::get_inputs(input_t* input)
{
    input->button_inside = _button->get_state();
    input->button_outside = _button2->get_state();
    input->sensor_closed = _lightbarrier->get_state();
    input->sensor_opened = _lightbarrier2->get_state();
    return *input;

}

events_t Inputs::get_events(events_t* event)
{
   
    event->close_button_pressed = _edge_button->detect_edge();
    event->open_button_pressed = _edge_button2->detect_edge();
    //event->light_barrier_1_reached = _edge_lightbarrier.detect_edge();
    //event->light_barrier_2_reached = _edge_lightbarrier2.detect_edge();
    return *event;


}
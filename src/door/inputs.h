#pragma once
#include <door/structs.h>


class Inputs
{
public:


    Inputs(PushButton* button, PushButton* button2, LightBarrier* lightbarrier, LightBarrier* lightbarrier2);
    ~Inputs();

    // void check(const Events& events);
    input_t get_inputs(input_t* input);
    events_t get_events(events_t* event);

    

private:

    PushButton* _button;
    PushButton* _button2;
    LightBarrier* _lightbarrier;
    LightBarrier* _lightbarrier2;

    EdgeDetector *_edge_button;
    EdgeDetector *_edge_button2;
    //EdgeDetector _edge_lightbarrier;
    //EdgeDetector _edge_lightbarrier;

};
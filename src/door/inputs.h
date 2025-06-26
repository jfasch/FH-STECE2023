#pragma once
#include <door/structs.h>


class Inputs
{
public:
    Inputs(PushButton* button, PushButton* button2, LightBarrier* lightbarrier, LightBarrier* lightbarrier2);
    ~Inputs();

    // void check(const Events& events);
    input_t get_inputs();
    events_t get_events();

    
private:
    PushButton* _button;
    PushButton* _button2;
    LightBarrier* _lightbarrier;
    LightBarrier* _lightbarrier2;

    EdgeDetector *_edge_button;
    EdgeDetector *_edge_button2;
};
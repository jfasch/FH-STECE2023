#pragma once
#include <door/structs.h>


typedef struct output
{
    bool motor_left = false;
    bool motor_right = false;
    bool display = false;
}output_t;



class Door
{
public:
    enum State
    {
        INIT,
        CLOSED,
        OPENING,
        OPENED,
        ERROR_MIDDLE_POSITION,
        ERROR_SOMETHING_BADLY_WRONG,
    };

    Door();
    
    // void check(const Events& events);
    output_t init(const input_t input);
    output_t cyclic(const events_t event);

    // for tests only
    void set_state(State state) { _state = state; }
    State get_state() const { return _state; }

private:
    State _state;
};
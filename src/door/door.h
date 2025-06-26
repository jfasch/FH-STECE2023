#pragma once

typedef struct input
{
    bool sensor_closed = false;
    bool sensor_opened = false;
    bool button_outside = false;
    bool button_inside = false;
}input_t;

typedef struct output
{
    bool motor_backward = false;
    bool motor_forward = false;
    bool motor_stop = false;
    bool display = false;
}output_t;

typedef struct events
{
    bool open_button_pressed = false;
    bool close_button_pressed = false;
    bool light_barrier_1_reached = false;
    bool light_barrier_2_reached = false;
}events_t;

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
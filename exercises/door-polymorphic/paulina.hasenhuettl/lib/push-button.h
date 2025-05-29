#pragma once

class PushButton
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };


    PushButton(State state);
    virtual ~PushButton();

    virtual State get_state() const;
    
    // for tests only
    virtual void set_state(State state);

private:
    State _state;
};

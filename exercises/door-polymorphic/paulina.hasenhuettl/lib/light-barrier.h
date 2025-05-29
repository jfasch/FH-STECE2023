#pragma once

class LightBarrier
{
public:
    enum class State
        {
            BEAM_SOLID,
            BEAM_BROKEN,
        };

     explicit LightBarrier(State state) : _state(state) {}
    
    virtual ~LightBarrier() = default;
    virtual State get_state() const { return _state; } 
    // for tests only
    virtual void set_state(State state) { _state = state; }

private:
    State _state;
};





    
   

    

   

    



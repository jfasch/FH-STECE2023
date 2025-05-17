#pragma once


enum LightBarrierState
{
    BEAM_SOLID,
    BEAM_BROKEN,
};

class LightBarrier
{
    private:
    LightBarrierState state;


    public:
    LightBarrier(LightBarrierState state); 
         
    LightBarrierState LightBarrier_get_state() const;
   

    void set_state(LightBarrierState state); 


};

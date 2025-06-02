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
    LightBarrier(LightBarrierState stateInit); 
         
    LightBarrierState get_state() const;
   
//test 
    void set_state(LightBarrierState stateSet); 


};

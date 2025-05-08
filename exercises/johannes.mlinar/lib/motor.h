#pragma once

class Motor{
    public:
    enum MotorDirection
    {
        IDLE,
        FORWARD,
        BACKWARD,
    };

    

    Motor(MotorDirection direction){
        this->_direction=direction;
    }
    Motor(){
        
    }
    MotorDirection get_direction();
    void forward();
    void backward();
    void stop();

    private:
    MotorDirection _direction;
  
};

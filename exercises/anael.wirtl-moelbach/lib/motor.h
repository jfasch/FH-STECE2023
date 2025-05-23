#pragma once

class Motor{


public: 
enum class MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

private:
    MotorDirection direction;

    
public: 

Motor(): direction (MotorDirection::MOTOR_IDLE) {}

void init(MotorDirection dir){
    direction = dir;
}

void forward(){
    direction = MotorDirection::MOTOR_FORWARD;
}

void backward()
{
    direction = MotorDirection::MOTOR_BACKWARD;
}

void stop(){
    direction = MotorDirection::MOTOR_IDLE;
}

// for tests only
MotorDirection get_direction() const{
    return direction;
}

};




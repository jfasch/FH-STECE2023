#pragma once

enum MotorDirection
{
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
};

class Motor
{
public:
    
    Motor(MotorDirection direction = MOTOR_IDLE);

    void forward();     
    void backward();    
    void stop();        

    
    MotorDirection getDirection() const;

private:
    MotorDirection direction_;
};

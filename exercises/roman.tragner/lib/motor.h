#pragma once


enum MotorDirection
{
    IDLE,
    FORWARD,
    BACKWARD,
};

class Motor
{
    private:
    MotorDirection direction;


    public:
    Motor();
    explicit Motor(MotorDirection direction);
    void init(MotorDirection direction);
    void forward();
    void backward();
    void stop();
    
    // for tests only
    MotorDirection getDirection() const;

};





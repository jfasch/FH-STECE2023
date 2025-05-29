#pragma once

enum class MotorDirection
{
    IDLE,
    FORWARD,
    BACKWARD,
};

class Motor
{
public:
    Motor();
    explicit Motor(MotorDirection direction);
    
    void init(MotorDirection direction);
    void forward();
    void backward();
    void stop();
    
    // For tests only
    MotorDirection getDirection() const;

private:
    MotorDirection direction;
};

#pragma once


enum class MotorDirection
{
    Idle,
    Forward,
    Backward,
};

class Motor
{
public:
    Motor(MotorDirection direction = MotorDirection::Idle)
        : direction(direction) {}

    void forward() { direction = MotorDirection::Forward; }
    void backward() { direction = MotorDirection::Backward; }
    void stop() { direction = MotorDirection::Idle; }

    // For tests only
    MotorDirection getDirection() const { return direction; }

private:
    MotorDirection direction;
};

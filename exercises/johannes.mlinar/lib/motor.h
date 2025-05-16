#pragma once

enum class MotorDirection {
    IDLE,
    FORWARD,
    BACKWARD
};

class Motor {
public:
    Motor(MotorDirection dir = MotorDirection::IDLE) : direction(dir) {}

    void forward()   { direction = MotorDirection::FORWARD; }
    void backward()  { direction = MotorDirection::BACKWARD; }
    void stop()      { direction = MotorDirection::IDLE; }

    MotorDirection getDirection() const { return direction; }

private:
    MotorDirection direction;
};

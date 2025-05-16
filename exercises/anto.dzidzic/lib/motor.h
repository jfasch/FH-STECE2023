#pragma once


class Motor {
public:

    enum Direction {
    MOTOR_IDLE,
    MOTOR_FORWARD,
    MOTOR_BACKWARD
    };

    Motor(Direction initial = MOTOR_IDLE) : direction(initial) {}

    Direction getDirection() const {
        return direction;
    }

    void forward() {
        direction = MOTOR_FORWARD;
    }

    void backward() {
        direction = MOTOR_BACKWARD;
    }

    void stop() {
        direction = MOTOR_IDLE;
    }
    

private:
    Direction direction;
};

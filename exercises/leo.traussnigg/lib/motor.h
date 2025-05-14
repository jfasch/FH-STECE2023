#pragma once

class Motor {
public:
    enum class Direction {
        IDLE,
        FORWARD,
        BACKWARD,
    };

    Motor(Direction direction = Direction::IDLE)
        : direction_(direction) {}

    void forward() {
        direction_ = Direction::FORWARD;
    }

    void backward() {
        direction_ = Direction::BACKWARD;
    }

    void stop() {
        direction_ = Direction::IDLE;
    }

    // For tests only
    Direction getDirection() const {
        return direction_;
    }

private:
    Direction direction_;
};

#pragma once


class Motor
{
public:
    enum class Direction
    {
        IDLE,
        FORWARD,
        BACKWARD,
    };

    Motor(Direction direction);
    void forward();
    void backward();
    void stop();

    // for tests only
    Direction get_direction() const;

private:
    Direction _direction;
};


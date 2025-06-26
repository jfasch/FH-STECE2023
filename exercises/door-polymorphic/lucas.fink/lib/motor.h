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

    // for tests only? (Door uses for a sanity check)
    Direction get_direction() const;

<<<<<<< HEAD
private:
    Direction _direction;
=======
>>>>>>> 18bd18d (light-barrier.gpio)
};


#pragma once

/*
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

private:
    Direction _direction;
};
*/


class Motor
{
public:
    virtual ~Motor() = default;
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void stop() = 0;

    Direction get_direction() const;

    enum class Direction
    {
        IDLE,
        FORWARD,
        BACKWARD,
    };

private:
    Direction _direction;
};
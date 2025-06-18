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

    explicit Motor(Direction direction = Direction::IDLE);
    
    void forward();
    void backward();
    void stop();
    
    // for tests only
    Direction get_direction() const;

private:
    Direction direction_;
};

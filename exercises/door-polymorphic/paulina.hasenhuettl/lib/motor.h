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

    explicit Motor(Direction dir) : _direction(dir) {}

    virtual ~Motor() = default;  //virtueller Destruktor (glaub ich?)

    virtual void forward() { _direction = Direction::FORWARD; }
    virtual void backward() { _direction = Direction::BACKWARD; }
    virtual void stop() { _direction = Direction::IDLE; }

    virtual Direction get_direction() const { return _direction; }

private:
    Direction _direction;
};
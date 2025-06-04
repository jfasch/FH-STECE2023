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

    virtual ~Motor() = default;
    virtual Direction get_direction() const = 0;

    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void stop() = 0;

 
};


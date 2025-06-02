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

    virtual ~Motor() = default;                        // <-- dogmatic virtual destructor
    virtual void forward() = 0;                        // <-- pure virtual methods
    virtual void backward() = 0;
    virtual void stop() = 0;
    virtual Direction get_direction() const = 0;
};


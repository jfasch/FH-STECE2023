#pragma once

class Motor
{
    public:
    
    enum Direction
    {
        IDLE,
        FORWARD,
        BACKWARD,
    };

    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void stop() = 0;
    virtual Direction get_direction() const = 0;
};
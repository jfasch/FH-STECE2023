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

        Motor(Direction initialdirection = Direction::IDLE);

        void forward();
        void backward();
        void stop();

        Direction getDirection() const;
        
    private:
        Direction direction;
};
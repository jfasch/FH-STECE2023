#pragma once


enum class MotorDirection
{
    IDLE,
    FORWARD,
    BACKWARD,
};

class Motor
{
    private:
        MotorDirection _direction;
    
    public:
        Motor(MotorDirection direction);

        void forward();
        void backward();
        void stop();
        
        // for tests only
        MotorDirection get_direction() const { return _direction; };
};

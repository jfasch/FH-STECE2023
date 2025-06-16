#pragma once

class IMotor {
public:

    enum class Direction {
        IDLE,
        FORWARD,
        BACKWARD
    };

    virtual ~IMotor() = default;
    
    // Nur Methoden, die von Door benutzt oder von Tests überprüft werden
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void stop() = 0;

    virtual Direction get_direction() const = 0;
};
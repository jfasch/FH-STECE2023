#include "motor.h"
#include "push-button.h"
#include "light-barrier.h"

class Door
{
public:
    enum class State
    {
        OPENED,
        CLOSED,
        OPENING,
        CLOSING,
    };

    Door(IMotor* motor,
         IPushButton* close_button,
         IPushButton* open_button,
         ILightBarrier* closed_sensor,
         ILightBarrier* opened_sensor);

    void check();
    State get_state() const;

private:
    IMotor* _motor;
    IPushButton* _close_button;
    IPushButton* _open_button;
    ILightBarrier* _closed_sensor;
    ILightBarrier* _opened_sensor;

    State _state;
};

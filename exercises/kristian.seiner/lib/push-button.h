#pragma once

/*
enum PushButtonState
{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED,
};

struct PushButton
{
    PushButtonState state;
};

void PushButton_init(PushButton* self, PushButtonState state);
PushButtonState PushButton_get_state(PushButton* self);

// for tests only
void PushButton_set_state(PushButton* self, PushButtonState state);
*/

enum PushButtonState{
    PUSHBUTTON_PRESSED,
    PUSHBUTTON_RELEASED
};

class PushButton{

    private:
        PushButtonState state;

    public:
        PushButton(PushButtonState state){
            this->state = state;
        }

        void PushButton_set_state(PushButtonState state){
            this-> state = state;
        }

        PushButtonState PushButton_get_state(){
            return state;
        }

        ~PushButton();

};


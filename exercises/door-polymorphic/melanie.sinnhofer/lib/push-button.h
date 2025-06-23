#pragma once

class PushButton
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };

    virtual ~PushButton() = default;                      // <-- virtual destructor
    virtual State get_state() const = 0;                  // <-- pure virtual method
};
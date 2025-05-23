#pragma once

class PushButton
{
public:
    enum State
    {
        PRESSED,
        RELEASED,
    };

public:
    virtual ~PushButton() = default;
    virtual State get_state() const = 0;

};

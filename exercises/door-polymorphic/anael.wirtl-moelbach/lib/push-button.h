#pragma once

class IPushButton
{
public:
    enum class State
    {
        PRESSED,
        RELEASED,
    };

    virtual ~IPushButton() = default;

    virtual State get_state() const = 0;
};

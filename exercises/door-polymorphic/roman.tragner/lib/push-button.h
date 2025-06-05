#pragma once

class PushButton
{
public:
    enum class State {
        PRESSED,
        RELEASED,
    };

    virtual ~PushButton() = default;

    // Interface: keine Implementierung
    virtual State get_state() const = 0;
};
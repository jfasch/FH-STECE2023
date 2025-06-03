#pragma once

class Interface
{
public:
    virtual ~Interface() = default;
    virtual void method() const = 0;
};

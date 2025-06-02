#pragma once

#include "interface.h"

class Implementation2 : public Interface
{
public:
    Implementation2(const char* s);
    ~Implementation2() override;
    void method() const override;
private:
    char* _s;
};

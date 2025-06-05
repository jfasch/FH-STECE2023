#pragma once

#include "interface.h"

class Implementation1 : public Interface
{
public:
    Implementation1(int num);
    void method() const;
private:
    int _num;
};

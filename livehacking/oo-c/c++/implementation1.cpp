#include "implementation1.h"

#include <iostream>


Implementation1::Implementation1(int num)
: _num(num) {}

void Implementation1::method() const
{
    std::cout << __PRETTY_FUNCTION__ << ": " << _num << std::endl;
}

#include "implementation2.h"

#include <iostream>
#include <cstring>


Implementation2::Implementation2(const char* s)
: _s(new char[strlen(s)+1])
{
    strcpy(_s, s);
}

Implementation2::~Implementation2()
{
    delete[] _s;
}

void Implementation2::method() const
{
    std::cout << __PRETTY_FUNCTION__ << ": " << _s  << std::endl;
}

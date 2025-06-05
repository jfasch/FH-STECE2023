#pragma once

#include "interface.h"

struct Implementation2
{
    struct Interface _iface; // jjj is-a
    char* _s;
};

void Implementation2_constructor(struct Implementation2* this, const char* s);

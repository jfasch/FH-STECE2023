#pragma once

#include "interface.h"

struct Implementation1
{
    struct Interface _iface; // jjj is-a
    int _num;
};

void Implementation1_constructor(struct Implementation1* this, int num);

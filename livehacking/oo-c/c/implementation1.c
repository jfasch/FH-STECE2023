#include "implementation1.h"

#include <stdio.h>

static void dtor(struct Interface* this) {}

static void method(const struct Interface* this)
{
    struct Implementation1* impl_this = (struct Implementation1*)this; // jjj downcast
    printf("%s: %d\n", __PRETTY_FUNCTION__, impl_this->_num);
}

void Implementation1_constructor(struct Implementation1* this, int num)
{
    Interface_vtable_init(&this->_iface, dtor, method); // jjj vtable

    this->_num = num;
}

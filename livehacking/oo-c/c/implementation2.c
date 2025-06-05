#include "implementation2.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static void dtor(struct Interface* this)
{
    struct Implementation2* impl_this = (struct Implementation2*)this;
    free(impl_this->_s);
}

static void method(const struct Interface* this)
{
    struct Implementation2* impl_this = (struct Implementation2*)this;
    printf("%s: %s\n", __PRETTY_FUNCTION__, impl_this->_s);
}

void Implementation2_constructor(struct Implementation2* this, const char* s)
{
    Interface_vtable_init(&this->_iface, dtor, method);

    this->_s = malloc(strlen(s)+1);
    strcpy(this->_s, s);
}


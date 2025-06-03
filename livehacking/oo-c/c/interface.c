#include "interface.h"

void Interface_vtable_init(struct Interface* this, destructor_func destructor, method_func method)
{
    this->destructor = destructor;
    this->method = method;
};

void Interface_destructor(struct Interface* this)
{
    this->destructor(this);
}

void Interface_method(const struct Interface* this)
{
    this->method(this);
}

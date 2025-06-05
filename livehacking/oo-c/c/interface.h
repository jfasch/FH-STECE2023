#pragma once

struct Interface;

typedef void (*destructor_func)(struct Interface* this);
typedef void (*method_func)(const struct Interface* this); // jjj const

struct Interface
{
    destructor_func destructor;
    method_func method;
};

void Interface_vtable_init(struct Interface* this, destructor_func destructor, method_func method);
void Interface_destructor(struct Interface* this);
void Interface_method(const struct Interface* this);

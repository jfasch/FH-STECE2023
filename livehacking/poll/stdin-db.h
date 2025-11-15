#pragma once

#include "eventloop.h"
#include "database.h"

class StdinToDatabase : public InputHandler
{
public:
    StdinToDatabase(Database& db);
    void hookup(Eventloop&);
    EventAction ready(int fd) override;

private:
    Database& _db;
};

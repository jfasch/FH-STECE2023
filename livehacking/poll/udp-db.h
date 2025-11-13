#pragma once

#include "database.h"
#include "eventloop.h"

#include <string>

class UDPToDatabase : public InputHandler
{
public:
    UDPToDatabase(const std::string& addr, short port, Database& db);
    ~UDPToDatabase() override;
    void hookup(Eventloop&);
    EventAction ready(int fd) override;

private:
    int _socket;
    Database& _db;
};

#pragma once

#include <string>

struct Record
{
public:
    Record() = default;
    Record(int id, const std::string& firstname, const std::string& lastname)
    : id(id), firstname(firstname), lastname(lastname) {}

    operator bool() const { return id != -1; }

    const int id = -1;
    const std::string firstname; 
    const std::string lastname;
};

Record split_line(const std::string& line);

class Database
{
public:
    void insert(const Record&);
    void commit();
    void rollback();
};



#include "stdin-db.h"

#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdexcept>
#include <format>

StdinToDatabase::StdinToDatabase(Database& db)
: _db(db) {}

void StdinToDatabase::hookup(Eventloop& loop)
{
    loop.register_input(STDIN_FILENO, this);
}

EventAction StdinToDatabase::ready(int fd)
{
    assert(fd == STDIN_FILENO);

    char buffer[64];
    ssize_t nread = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (nread == -1)
        throw std::runtime_error(std::format("read failed: {} ({})", strerror(errno), errno));

    if (nread == 0)
        return EventAction::Quit;

    std::string line(buffer, nread);
    if (Record r = split_line(line))
        _db.insert(r);
    else
        throw std::runtime_error(std::format("bad record: {}", line));

    return EventAction::Continue;
}

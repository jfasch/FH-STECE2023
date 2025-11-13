#include "udp-db.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdexcept>
#include <format>

UDPToDatabase::UDPToDatabase(const std::string& addrstr, short port, Database& db)
: _db(db)
{
    _socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (_socket == -1)
        throw std::runtime_error(std::format("cannot allocate socket: {} ({})", strerror(errno), errno));

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
    };
    if (inet_pton(AF_INET, addrstr.c_str(), &addr.sin_addr) != 1)
        throw std::runtime_error(std::format("{} is not a valid address: {} ({})", addrstr, strerror(errno), errno));

    if (bind(_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        throw std::runtime_error(std::format("cannot bind socket: {} ({})", strerror(errno), errno));
}

UDPToDatabase::~UDPToDatabase()
{
    if (_socket != -1)
        close(_socket);
}

void UDPToDatabase::hookup(Eventloop& loop)
{
    loop.register_input(_socket, this);
}
    
EventAction UDPToDatabase::ready(int fd)
{
    assert(fd == _socket);

    char buffer[64];
    ssize_t nread = read(_socket, buffer, sizeof(buffer));
    if (nread == -1)
        throw std::runtime_error(std::format("read failed: {} ({})", strerror(errno), errno));

    std::string line(buffer, nread);
    if (Record r = split_line(line))
        _db.insert(r);
    else
        throw std::runtime_error(std::format("bad record: {}", line));

    return EventAction::Continue;
}

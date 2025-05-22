#include <iostream>
#include <unistd.h>
#include <fcntl.h>

class File
{
public:
    File(const std::string& filename)
    {
        _fd = open(filename.c_str(), O_RDONLY);
    }
    ~File()
    {
        std::cout << "closing file" << std::endl;
        close(_fd);
    }
private:
    int _fd;
};

int main()
{
    [[maybe_unused]] File f("/etc/passwd");
    return 0;
}

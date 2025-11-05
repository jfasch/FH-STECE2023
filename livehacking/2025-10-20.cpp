#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <print>

int main(int argc, char** argv)
{
    int fd = open("/tmp/somefile", O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    

    close(fd);

    return 0;
}

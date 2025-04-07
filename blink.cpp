#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

char value_file[] = "/sys/class/gpio/gpio533/value";

// v=0; while true; do sleep 0.5; v=$(($v+1)); v=$(($v%2)); echo $v > value; done

int main()
{
    bool v = false;
    while (true) {
        timespec interval;
        interval.tv_sec = 0;
        interval.tv_nsec = 1000*1000*1000/2;
        
        /*int rv* rv?*/ nanosleep(&interval, nullptr);

        std::cout << "toggle" << std::endl;

        int fd = open(value_file, O_WRONLY);
        char content[2];
        if (v)
            content[0] = '1';
        else
            content[0] = '0';
        content[1] = '\n';
        write(fd, content, 2);

        v = !v;
  }
  return 0;
}

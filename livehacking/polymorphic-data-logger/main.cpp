#include "sensor-mock.h"
#include "sensor-file.h"
#include "logger.h"

#include <thread>
#include <chrono>
using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    MockSensor sensor(42.666);
    // FileSensor sensor(argv[1]);
    Logger logger(&sensor);

    while (true) {
        logger.log_one();
        std::this_thread::sleep_for(500ms);
    }

    return 0;
}

#include "timespec.h"

#include <cassert>


TimeSpec TimeSpec::now_monotonic()
{
    timespec now;
    int error = clock_gettime(CLOCK_MONOTONIC, &now);
    assert(!error);
    return now;
}

TimeSpec TimeSpec::from_milliseconds(unsigned long ms)
{
    return TimeSpec(0, ms*1000*1000);
}

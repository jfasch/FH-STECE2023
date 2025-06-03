#include "timespec.h"

#include <cassert>


TimeSpec TimeSpec::now_monotonic()
{
    timespec now;
    int error = clock_gettime(CLOCK_MONOTONIC, &now);
    assert(!error);
    return now;
}

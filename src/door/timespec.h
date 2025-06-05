#pragma once

#include <time.h>
#include <cassert>


/** 
 * @brief TimeSpec: good old struct timespec with strong-ordering relationship and arithmetic
 */
struct TimeSpec : public timespec
{
    static TimeSpec now_monotonic();
    static TimeSpec from_milliseconds(unsigned long ms);

    TimeSpec()
    {
        tv_sec = tv_nsec = 0;
    }

    TimeSpec(const timespec& from)
    {
        timespec::operator=(from);
        assert(tv_nsec < ONE_BILLION_NANOS);
    }

    TimeSpec(time_t sec, time_t nsec)
    {
        tv_sec = sec;
        tv_nsec = nsec;

        assert(tv_nsec < ONE_BILLION_NANOS);
    }

    bool operator==(const TimeSpec& rhs) const
    {
        return tv_sec == rhs.tv_sec && tv_nsec == rhs.tv_nsec;
    }
    bool operator!=(const TimeSpec& rhs) const { return !(*this == rhs); }

    bool operator<(const TimeSpec& rhs) const
    {
        if (tv_sec < rhs.tv_sec)
            return true;
        return tv_nsec < rhs.tv_nsec;
    }
    bool operator> (const TimeSpec& rhs) const { return !(*this < rhs || *this == rhs); }
    bool operator>=(const TimeSpec& rhs) const { return !(*this < rhs); }
    bool operator<=(const TimeSpec& rhs) const { return *this == rhs || *this < rhs; }

    TimeSpec operator+(const TimeSpec& rhs) const
    {
        time_t sec = tv_sec + rhs.tv_sec;
        time_t nsec = tv_nsec + rhs.tv_nsec;

        if (nsec >= ONE_BILLION_NANOS) {
            sec += nsec / ONE_BILLION_NANOS;
            nsec = nsec % ONE_BILLION_NANOS;
        }
        return TimeSpec(sec, nsec);
    }

    TimeSpec operator-(const TimeSpec& rhs) const
    {
        time_t sec = tv_sec - rhs.tv_sec;
        time_t nsec = tv_nsec - rhs.tv_nsec;

        if (nsec < 0) {
            --sec;
            nsec = ONE_BILLION_NANOS + nsec;
        }
        return TimeSpec(sec, nsec);
    }

    static const time_t ONE_BILLION_NANOS = 1000*1000*1000;
};

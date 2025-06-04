#pragma once

#include <time.h>


/** 
 * @brief TimeSpec: timespec with strong ordering relationship
 */

struct TimeSpec : public timespec
{
    static TimeSpec now_monotonic();

    TimeSpec()
    {
        tv_sec = tv_nsec = 0;
    }

    TimeSpec(const timespec& from)
    {
        timespec::operator=(from);
    }

    TimeSpec(time_t sec, time_t nsec)
    {
        tv_sec = sec;
        tv_nsec = nsec;
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
        if (nsec > 1000*1000*1000) {
            sec += nsec / 1000*1000*1000;
            nsec = nsec % 1000*1000*1000;
        }
        return TimeSpec(sec, nsec);
    }
};

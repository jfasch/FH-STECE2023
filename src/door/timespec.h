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
};

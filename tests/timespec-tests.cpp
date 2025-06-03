#include <door/timespec.h>

#include <gtest/gtest.h>
#include <time.h>


TEST(timespec_suite, from_timespec)
{
    timespec good_old = {
        .tv_sec = 100,
        .tv_nsec = 550,
    };

    TimeSpec fancy_new = good_old;

    ASSERT_EQ(fancy_new.tv_sec, 100);
    ASSERT_EQ(fancy_new.tv_nsec, 550);
}

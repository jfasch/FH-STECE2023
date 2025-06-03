#include <door/timespec.h>

#include <gtest/gtest.h>
#include <time.h>


TEST(timespec_suite, default_ctor)
{
    TimeSpec fancy;
    ASSERT_EQ(fancy.tv_sec, 0);
    ASSERT_EQ(fancy.tv_nsec, 0);
}

TEST(timespec_suite, ctor_from_good_old)
{
    timespec good_old = {
        .tv_sec = 100,
        .tv_nsec = 550,
    };

    TimeSpec fancy_new = good_old;                     // <-- constructor
    ASSERT_EQ(fancy_new.tv_sec, 100);
    ASSERT_EQ(fancy_new.tv_nsec, 550);
}

TEST(timespec_suite, explicit_ctor)
{
    TimeSpec t(100, 550);
    ASSERT_EQ(t.tv_sec, 100);
    ASSERT_EQ(t.tv_nsec, 550);
}

TEST(timespec_suite, copy_from_good_old)
{
    timespec good_old = {
        .tv_sec = 100,
        .tv_nsec = 550,
    };

    TimeSpec fancy_new;                                // <-- default-constructor
    fancy_new = good_old;                              // <-- copy

    ASSERT_EQ(fancy_new.tv_sec, 100);
    ASSERT_EQ(fancy_new.tv_nsec, 550);
}

TEST(timespec_suite, copy_ctor)
{
    TimeSpec orig(100, 550);    
    TimeSpec copy(orig);                               // <-- copy constructor

    ASSERT_EQ(copy.tv_sec, 100);
    ASSERT_EQ(copy.tv_nsec, 550);
}

TEST(timespec_suite, assignment_operator)
{
    TimeSpec orig(100, 550);
    TimeSpec copy;                                     // <-- default constructor

    copy = orig;                                       // <-- assignment operator

    ASSERT_EQ(copy.tv_sec, 100);
    ASSERT_EQ(copy.tv_nsec, 550);
}

TEST(timespec_suite, less)
{
    TimeSpec older(100, 550);

    // TimeSpec < TimeSpec
    {
        TimeSpec newer1(100, 551);
        TimeSpec newer2(101, 550);
        TimeSpec newer3(101, 551);

        ASSERT_TRUE(older < newer1);
        ASSERT_TRUE(older < newer2);
        ASSERT_TRUE(older < newer3);
    }

    // TimeSpec < (good old) timespec
    {
        timespec newer1 = { .tv_sec = 100, .tv_nsec = 551 };
        timespec newer2 = { .tv_sec = 101, .tv_nsec = 550 };
        timespec newer3 = { .tv_sec = 101, .tv_nsec = 551 };

        ASSERT_TRUE(older < newer1);
        ASSERT_TRUE(older < newer2);
        ASSERT_TRUE(older < newer3);
    }
}

TEST(timespec_suite, equals_and_notequals)
{
    ASSERT_TRUE(TimeSpec(100, 550) == TimeSpec(100, 550));
    ASSERT_FALSE(TimeSpec(100, 551) == TimeSpec(100, 550));
    ASSERT_FALSE(TimeSpec(101, 550) == TimeSpec(100, 550));

    ASSERT_FALSE(TimeSpec(100, 550) != TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(100, 551) != TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(101, 550) != TimeSpec(100, 550));
}

TEST(timespec_suite, greater)
{
    ASSERT_TRUE(TimeSpec(101, 550) > TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(100, 551) > TimeSpec(100, 550));
}

TEST(timespec_suite, less_equal)
{
    ASSERT_TRUE(TimeSpec(100, 550) <= TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(100, 550) <= TimeSpec(100, 551));
    ASSERT_TRUE(TimeSpec(100, 550) <= TimeSpec(101, 550));
}

TEST(timespec_suite, greater_equal)
{
    ASSERT_TRUE(TimeSpec(100, 550) >= TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(100, 551) >= TimeSpec(100, 550));
    ASSERT_TRUE(TimeSpec(101, 550) >= TimeSpec(100, 550));
}

TEST(timespec_suite, now_monotonic)
{
    [[maybe_unused]] TimeSpec now = TimeSpec::now_monotonic();
    // hard to test which time it returned :-)
}

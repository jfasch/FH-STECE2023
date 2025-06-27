#include <door/timespec.h>
#include <iostream>
#include <gtest/gtest.h>
#include <time.h>
#include <door/push-button-mock.h>
#include <door/event-edge-detector.h>
#include <door/timespec.h>

TEST(eventedge_suite, rising_edge)
{
    const TimeSpec debounce(0, 0);
    TimeSpec time(0, 500);
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector edge(&button, debounce); 
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::RISING);

}

TEST(eventedge_suite, falling_edge)
{
    const TimeSpec debounce(0, 0);
    TimeSpec time(0, 500);
    PushButtonMock button(PushButton::State::PRESSED);
    EdgeDetector edge(&button, debounce);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::FALLING);
}

TEST(eventedge_suite, none_edge)
{
    const TimeSpec debounce(0, 0);
    TimeSpec time;
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector edge(&button, time); 
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);

    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::RISING);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
}

TEST(eventedge_suite, debounce_rising)
{
    PushButtonMock button(PushButton::State::RELEASED);
    const TimeSpec debounce(0, 1000*1000*100);
    TimeSpec now;
    EdgeDetector edge(&button, debounce); 

    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);

    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);
     
    now.tv_nsec = 1000*1000*200;
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::RISING);
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);



}

TEST(eventedge_suite, debounce_falling)
{
    PushButtonMock button(PushButton::State::PRESSED);
    const TimeSpec debounce(0, 1000*1000*100);
    TimeSpec now;
    EdgeDetector edge(&button, debounce);

    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);

    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);
     
    now.tv_nsec = 1000*1000*200;
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::FALLING);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);
}

TEST(eventedge_suite, time_smaller_than_debounce_time)
{
    PushButtonMock button(PushButton::State::PRESSED);
    const TimeSpec debounce(0, 1000*1000*300);
    TimeSpec now;
    EdgeDetector edge(&button, debounce);

    now.tv_nsec = 1000*1000*200;
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);

    now.tv_nsec = 1000*1000*300;
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::FALLING);
}

TEST(eventedge_suite, debounce_jitter)
{
    PushButtonMock button(PushButton::State::RELEASED);
    const TimeSpec debounce(0, 1000*1000*300);
    TimeSpec now(0, 1000*1000*300);
    EdgeDetector edge(&button, debounce);

    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::RISING);
    button.set_state(PushButton::State::PRESSED);
    button.set_state(PushButton::State::RELEASED);
    button.set_state(PushButton::State::PRESSED);
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::NONE);

    now.tv_nsec = 1000*1000*700;
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(now), EdgeDetector::State::FALLING);
    
}
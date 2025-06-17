#include <door/timespec.h>
#include <iostream>
#include <gtest/gtest.h>
#include <time.h>
#include <door/push-button-mock.h>

TEST(eventedge_suite, rising_edge)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector Edge(); 
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(detect_edge(const TimeSpec& now), EdgeDetector::State::RISE);

}

TEST(eventedge_suite, falling_edge)
{
    PushButtonMock button(PushButton::State::PRESSED);
    EdgeDetector Edge(); 
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(detect_edge(const TimeSpec& now), EdgeDetector::State::FALL);

TEST(eventedge_suite, none_edge)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector Edge(); 
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);

    PushButtonMock button(PushButton::State::PRESSED);
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::RISE);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(Edge.detect_edge(const TimeSpec& now), EdgeDetector::State::NONE);
}

TEST(eventedge_suite, debounce_high)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector Edge(); 

}

TEST(eventedge_suite, debounce_low)
{
    
}
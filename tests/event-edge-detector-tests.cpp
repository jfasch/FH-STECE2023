#include <door/timespec.h>
#include <iostream>
#include <gtest/gtest.h>
#include <time.h>
#include <door/push-button-mock.h>
#include <door/event-edge-detector.h>

TEST(eventedge_suite, rising_edge)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector edge(&button); 
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::RISING);

}

TEST(eventedge_suite, falling_edge)
{
    PushButtonMock button(PushButton::State::PRESSED);
    EdgeDetector edge(&button);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::FALLING);
}

TEST(eventedge_suite, none_edge)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector edge(&button); 
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    
    button.set_state(PushButton::State::RELEASED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);

    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::RISING);
    
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
    button.set_state(PushButton::State::PRESSED);
    ASSERT_EQ(edge.detect_edge(), EdgeDetector::State::NONE);
}

/*TEST(eventedge_suite, debounce_high)
{
    PushButtonMock button(PushButton::State::RELEASED);
    EdgeDetector Edge(button); 
    TimeSpec time;
    while()
    {
        PushButtonMock button(PushButton::State::RELEASED);
        ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::RISE);
        
        button.set_state(PushButton::State::PRESSED);
        ASSERT_EQ(edge.detect_edge(time), EdgeDetector::State::NONE);
    }    

}

TEST(eventedge_suite, debounce_low)
{
    
}*/
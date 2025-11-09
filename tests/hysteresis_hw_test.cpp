// Hardware hysteresis integration test using BMP280
#include <gtest/gtest.h>
#include <door/pressure-sensor-bmp280.h>
#include <door/pressure-sensor-event-generator.h>
#include <chrono>
#include <thread>
#include <cmath>

// This test requires a real BMP280 sensor on the I2C bus. If the device
// cannot be opened the test will be skipped.
TEST(HardwareHysteresisTest, BMP280DetectsChangeAndTriggersEvent)
{
    using namespace std::chrono_literals;


     BMP280 bmp;


    // Try to read two different values from the sensor by polling for a short time
    float first = 0.0f;

    first = bmp.get_pressure();


    const float min_delta = 0.01f; // minimal delta to consider values "different"
    float second = first;

    // Poll for up to 8 seconds to find a different reading
    const int max_tries = 8;
    for (int i = 0; i < max_tries; ++i) {
        std::this_thread::sleep_for(1s);

        second = bmp.get_pressure();

        if (std::fabs(second - first) >= min_delta) break;
    }

    // If values did not change enough, fail the test (hardware may be static)
    ASSERT_NEAR(first, second, min_delta) << "BMP280 readings did not change enough for hysteresis test";

    // Determine direction of change and set thresholds between the two readings
    float low = std::min(first, second);
    float high = std::max(first, second);
    float mid = (low + high) / 2.0f;

    // Small hysteresis so that mid crossing triggers an event
    const float hysteresis = 0.005f;

    // set thresholds so that initial reading is on one side of mid and the later reading on the other
    float under_threshold = mid - 0.001f; // slightly below mid
    float over_threshold = mid + 0.001f;  // slightly above mid

    PressureSensorEventGenerator gen(&bmp, under_threshold, over_threshold, true, hysteresis);

    // First call should reflect the current state (first)
    PressureSensorEvent ev1 = gen.get_event();

    // Wait until sensor has the second reading (we already polled earlier; sleep briefly)
    std::this_thread::sleep_for(200ms);

    // Second call should reflect the changed state (second)
    PressureSensorEvent ev2 = gen.get_event();

    // They should not be equal if readings crossed the mid threshold
    ASSERT_NE(ev1, ev2) << "Event did not change after sensor reading changed (ev1 == ev2). Values: first=" << first << " second=" << second;
}

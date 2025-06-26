add_executable(
  door-tests

  door-tests.cpp
  timespec-tests.cpp
  event-edge-detector-tests.cpp
  inputs-tests.cpp

  outputs-tests.cpp
)
target_link_libraries(
  door-tests

  door
  gtest_main 
)
add_test(
  NAME door-tests 
  COMMAND door-tests
)

if (LIBGPIOD_FOUND)
  add_executable(gpio-read-value-loop gpio-read-value-loop.cpp)
  target_link_libraries(gpio-read-value-loop LIBGPIOD::LIBGPIOD)

  add_executable(motorLED-tests motorLED-tests.cpp)
  target_link_libraries(
    motorLED-tests
  
    door
    gtest_main
  )
else()
  message(WARNING "Skip motorLED-tests and gpio-read-value-loop because libgpiod not found")
endif()

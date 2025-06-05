add_executable(
  door-tests

  door-tests.cpp
  timespec-tests.cpp
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

if (LIBGPIODCXX_FOUND)
  add_executable(gpio-read-value-loop gpio-read-value-loop.cpp)
  target_link_libraries(gpio-read-value-loop LIBGPIODCXX::LIBGPIODCXX)
else()
  message(WARNING "Not building gpio-read-value-loop because libgpiod not found")
endif()

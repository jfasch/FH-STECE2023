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

add_executable(
  door-tests-christopher.winter

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-christopher.winter

  door-christopher.winter
  gtest_main 
)

add_test(
  NAME door-tests-christopher.winter
  COMMAND door-tests-christopher.winter
)

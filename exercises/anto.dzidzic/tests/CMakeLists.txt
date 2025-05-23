add_executable(
  door-tests-anto.dzidzic
  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-anto.dzidzic
  door-anto.dzidzic
  gtest_main 
)

add_test(
  NAME door-tests-anto.dzidzic
  COMMAND door-tests-anto.dzidzic
)

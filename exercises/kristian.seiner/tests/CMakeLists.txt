add_executable(
  door-tests-kristian.seiner

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-kristian.seiner

  door-kristian.seiner
  gtest_main 
)

add_test(
  NAME door-tests-kristian.seiner 
  COMMAND door-tests-kristian.seiner 
)

add_executable(
  door-tests-roman.tragner

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-roman.tragner

  door-roman.tragner
  gtest_main 
)

add_test(
  NAME door-tests-roman.tragner 
  COMMAND door-tests-roman.tragner 
)

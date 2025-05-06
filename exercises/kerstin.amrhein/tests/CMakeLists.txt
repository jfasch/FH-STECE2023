add_executable(
  door-tests-kerstin.amrhein

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-kerstin.amrhein

  door-kerstin.amrhein
  gtest_main 
)

add_test(
  NAME door-tests-kerstin.amrhein 
  COMMAND door-tests-kerstin.amrhein 
)

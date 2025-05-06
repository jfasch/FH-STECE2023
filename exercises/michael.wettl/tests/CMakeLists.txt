add_executable(
  door-tests-michael.wettl

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-michael.wettl

  door-michael.wettl
  gtest_main 
)

add_test(
  NAME door-tests-michael.wettl 
  COMMAND door-tests-michael.wettl 
)

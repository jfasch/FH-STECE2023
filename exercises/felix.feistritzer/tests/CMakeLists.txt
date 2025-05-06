add_executable(
  door-tests-felix.feistritzer

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-felix.feistritzer

  door-felix.feistritzer
  gtest_main 
)

add_test(
  NAME door-tests-felix.feistritzer
  COMMAND door-tests-felix.feistritzer
)

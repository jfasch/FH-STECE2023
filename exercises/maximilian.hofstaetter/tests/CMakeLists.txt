add_executable(
  door-tests-maximilian.hofstaetter

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-maximilian.hofstaetter

  door-maximilian.hofstaetter
  gtest_main 
)

add_test(
  NAME door-tests-maximilian.hofstaetter 
  COMMAND door-tests-maximilian.hofstaetter 
)

add_executable(
  door-tests-leo.traussnigg

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-leo.traussnigg

  door-leo.traussnigg
  gtest_main 
)

add_test(
  NAME door-tests-leo.traussnigg 
  COMMAND door-tests-leo.traussnigg 
)

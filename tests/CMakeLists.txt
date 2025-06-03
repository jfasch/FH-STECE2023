add_executable(
  door-tests

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp

  door-tests.cpp

  motor-polymorphic-tests.cpp
  lightbarrier-polymorphic-tests.cpp
  pushbutton-polymorphic-tests.cpp
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

add_executable(
  door-tests

  door-tests.cpp
  
  timespec-tests.cpp


  # these will become obsolete as we gain speed
  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp

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

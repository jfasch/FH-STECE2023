add_executable(
  door-tests-melanie.sinnhofer

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-melanie.sinnhofer

  door-melanie.sinnhofer
  gtest_main 
)

add_test(
  NAME door-tests-melanie.sinnhofer 
  COMMAND door-tests-melanie.sinnhofer 
)

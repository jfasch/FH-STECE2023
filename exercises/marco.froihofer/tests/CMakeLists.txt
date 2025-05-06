add_executable(
  door-tests-marco.froihofer

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-marco.froihofer

  door-marco.froihofer
  gtest_main 
)

add_test(
  NAME door-tests-marco.froihofer 
  COMMAND door-tests-marco.froihofer 
)

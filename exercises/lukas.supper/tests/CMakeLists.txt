add_executable(
  door-tests-lukas.supper

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-lukas.supper

  door-lukas.supper
  gtest_main 
)

add_test(
  NAME door-tests-lukas.supper 
  COMMAND door-tests-lukas.supper 
)

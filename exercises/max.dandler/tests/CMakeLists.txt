add_executable(
  door-tests-max.dandler

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-max.dandler

  door-max.dandler
  gtest_main 
)

add_test(
  NAME door-tests-max.dandler 
  COMMAND door-tests-max.dandler 
)

add_executable(
  door-tests-marcus.teichtmeister

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-marcus.teichtmeister

  door-marcus.teichtmeister
  gtest_main 
)

add_test(
  NAME door-tests-marcus.teichtmeister 
  COMMAND door-tests-marcus.teichtmeister 
)

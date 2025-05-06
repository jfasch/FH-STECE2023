add_executable(
  door-tests-benedikt.polivka

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-benedikt.polivka

  door-benedikt.polivka
  gtest_main 
)

add_test(
  NAME door-tests-benedikt.polivka
  COMMAND door-tests-benedikt.polivka
)

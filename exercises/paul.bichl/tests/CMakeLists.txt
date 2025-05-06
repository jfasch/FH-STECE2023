add_executable(
  door-tests-paul.bichl

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-paul.bichl

  door-paul.bichl
  gtest_main 
)

add_test(
  NAME door-tests-paul.bichl 
  COMMAND door-tests-paul.bichl 
)

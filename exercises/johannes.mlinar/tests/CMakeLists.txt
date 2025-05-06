add_executable(
  door-tests-johannes.mlinar

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-johannes.mlinar

  door-johannes.mlinar
  gtest_main 
)

add_test(
  NAME door-tests-johannes.mlinar
  COMMAND door-tests-johannes.mlinar
)

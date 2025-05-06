add_executable(
  door-tests-lorenz.kristl

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-lorenz.kristl

  door-lorenz.kristl
  gtest_main 
)

add_test(
  NAME door-tests-lorenz.kristl 
  COMMAND door-tests-lorenz.kristl 
)

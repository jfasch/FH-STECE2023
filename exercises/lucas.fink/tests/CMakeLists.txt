add_executable(
  door-tests-lucas.fink

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-lucas.fink

  door-lucas.fink
  gtest_main 
)

add_test(
  NAME door-tests-lucas.fink 
  COMMAND door-tests-lucas.fink 
)

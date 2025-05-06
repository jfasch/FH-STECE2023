add_executable(
  door-tests-matthias.winkler

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-matthias.winkler

  door-matthias.winkler
  gtest_main 
)

add_test(
  NAME door-tests-matthias.winkler 
  COMMAND door-tests-matthias.winkler 
)

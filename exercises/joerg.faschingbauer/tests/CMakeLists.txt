add_executable(
  door-tests-joerg.faschingbauer

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-joerg.faschingbauer

  door-joerg.faschingbauer
  gtest_main 
)

add_test(
  NAME door-tests-joerg.faschingbauer 
  COMMAND door-tests-joerg.faschingbauer 
)

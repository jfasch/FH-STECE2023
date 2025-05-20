add_executable(
  door-tests-polymorphic-joerg.faschingbauer

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-polymorphic-joerg.faschingbauer

  door-polymorphic-joerg.faschingbauer
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-joerg.faschingbauer 
  COMMAND door-polymorphic-tests-joerg.faschingbauer 
)

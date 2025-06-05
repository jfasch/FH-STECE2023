add_executable(
  door-tests-polymorphic-roman.tragner

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp

  door-tests.cpp

  # --- this is for you :* ---
   motor-polymorphic-tests.cpp
  # lightbarrier-polymorphic-tests.cpp
  # pushbutton-polymorphic-tests.cpp
)

target_link_libraries(
  door-tests-polymorphic-roman.tragner

  door-polymorphic-roman.tragner
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-roman.tragner 
  COMMAND door-polymorphic-tests-roman.tragner 
)
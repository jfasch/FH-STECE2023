add_executable(
  door-tests-polymorphic-kerstin.amrhein

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp

  door-tests.cpp

  # --- this is for you :* ---
  motor-polymorphic-tests.cpp
  lightbarrier-polymorphic-tests.cpp
  pushbutton-polymorphic-tests.cpp
)

target_link_libraries(
  door-tests-polymorphic-kerstin.amrhein

  door-polymorphic-kerstin.amrhein
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-kerstin.amrhein 
  COMMAND door-polymorphic-tests-kerstin.amrhein 
)

add_executable(
  door-tests-polymorphic-christopher.winter

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp

  door-tests.cpp

  # --- this is for you :* ---
  # motor-polymorphic-tests.cpp
  # lightbarrier-polymorphic-tests.cpp
  # pushbutton-polymorphic-tests.cpp
)

target_link_libraries(
  door-tests-polymorphic-christopher.winter

  door-polymorphic-christopher.winter
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-christopher.winter 
  COMMAND door-polymorphic-tests-christopher.winter 
)

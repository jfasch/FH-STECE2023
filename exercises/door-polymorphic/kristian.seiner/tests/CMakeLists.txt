add_executable(
  door-tests-polymorphic-kristian.seiner

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
  door-tests-polymorphic-kristian.seiner

  door-polymorphic-kristian.seiner
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-kristian.seiner 
  COMMAND door-polymorphic-tests-kristian.seiner 
)

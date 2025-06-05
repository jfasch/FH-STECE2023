add_executable(
  door-tests-polymorphic-lukas.supper

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
  door-tests-polymorphic-lukas.supper

  door-polymorphic-lukas.supper
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-lukas.supper 
  COMMAND door-polymorphic-tests-lukas.supper 
)

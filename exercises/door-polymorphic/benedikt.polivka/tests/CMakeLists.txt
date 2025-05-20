add_executable(
  door-tests-polymorphic-benedikt.polivka

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
  door-tests-polymorphic-benedikt.polivka

  door-polymorphic-benedikt.polivka
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-benedikt.polivka 
  COMMAND door-polymorphic-tests-benedikt.polivka 
)

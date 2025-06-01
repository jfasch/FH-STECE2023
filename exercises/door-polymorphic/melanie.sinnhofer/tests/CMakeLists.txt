add_executable(
  door-tests-polymorphic-melanie.sinnhofer

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
  door-tests-polymorphic-melanie.sinnhofer

  door-polymorphic-melanie.sinnhofer
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-melanie.sinnhofer 
  COMMAND door-polymorphic-tests-melanie.sinnhofer 
)

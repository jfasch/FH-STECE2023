add_executable(
  door-tests-polymorphic-marco.froihofer

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
  door-tests-polymorphic-marco.froihofer

  door-polymorphic-marco.froihofer
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-marco.froihofer 
  COMMAND door-polymorphic-tests-marco.froihofer 
)

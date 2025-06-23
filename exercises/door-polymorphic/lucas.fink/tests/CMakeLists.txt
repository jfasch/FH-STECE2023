add_executable(
  door-tests-polymorphic-lucas.fink

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
  door-tests-polymorphic-lucas.fink

  door-polymorphic-lucas.fink
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-lucas.fink 
  COMMAND door-polymorphic-tests-lucas.fink 
)

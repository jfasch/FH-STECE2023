add_executable(
  door-tests-polymorphic-michael.wettl

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
  door-tests-polymorphic-michael.wettl

  door-polymorphic-michael.wettl
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-michael.wettl 
  COMMAND door-polymorphic-tests-michael.wettl 
)

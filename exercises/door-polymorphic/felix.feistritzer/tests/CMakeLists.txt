add_executable(
  door-tests-polymorphic-felix.feistritzer

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
  door-tests-polymorphic-felix.feistritzer

  door-polymorphic-felix.feistritzer
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-felix.feistritzer 
  COMMAND door-polymorphic-tests-felix.feistritzer 
)

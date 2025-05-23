add_executable(
  door-tests-polymorphic-leo.traussnigg

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
  door-tests-polymorphic-leo.traussnigg

  door-polymorphic-leo.traussnigg
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-leo.traussnigg 
  COMMAND door-polymorphic-tests-leo.traussnigg 
)

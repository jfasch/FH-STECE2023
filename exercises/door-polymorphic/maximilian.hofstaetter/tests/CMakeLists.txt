add_executable(
  door-tests-polymorphic-maximilian.hofstaetter

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
  door-tests-polymorphic-maximilian.hofstaetter

  door-polymorphic-maximilian.hofstaetter
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-maximilian.hofstaetter 
  COMMAND door-polymorphic-tests-maximilian.hofstaetter 
)

add_executable(
  door-tests-polymorphic-anto.dzidzic

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
  door-tests-polymorphic-anto.dzidzic

  door-polymorphic-anto.dzidzic
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-anto.dzidzic 
  COMMAND door-polymorphic-tests-anto.dzidzic 
)

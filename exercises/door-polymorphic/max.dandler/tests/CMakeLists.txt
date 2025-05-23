add_executable(
  door-tests-polymorphic-max.dandler

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
  door-tests-polymorphic-max.dandler

  door-polymorphic-max.dandler
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-max.dandler 
  COMMAND door-polymorphic-tests-max.dandler 
)

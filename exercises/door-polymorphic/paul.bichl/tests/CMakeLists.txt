add_executable(
  door-tests-polymorphic-paul.bichl

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
  door-tests-polymorphic-paul.bichl

  door-polymorphic-paul.bichl
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-paul.bichl 
  COMMAND door-polymorphic-tests-paul.bichl 
)

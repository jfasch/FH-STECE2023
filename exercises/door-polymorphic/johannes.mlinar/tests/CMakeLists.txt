add_executable(
  door-tests-polymorphic-johannes.mlinar

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
  door-tests-polymorphic-johannes.mlinar

  door-polymorphic-johannes.mlinar
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-johannes.mlinar 
  COMMAND door-polymorphic-tests-johannes.mlinar 
)

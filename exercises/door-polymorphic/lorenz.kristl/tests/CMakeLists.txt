add_executable(
  door-tests-polymorphic-lorenz.kristl

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
  door-tests-polymorphic-lorenz.kristl

  door-polymorphic-lorenz.kristl
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-lorenz.kristl 
  COMMAND door-polymorphic-tests-lorenz.kristl 
)

add_executable(
  door-tests-polymorphic-paulina.hasenhuettl

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
  door-tests-polymorphic-paulina.hasenhuettl

  door-polymorphic-paulina.hasenhuettl
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-paulina.hasenhuettl 
  COMMAND door-polymorphic-tests-paulina.hasenhuettl 
)

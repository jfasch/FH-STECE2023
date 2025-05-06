add_executable(
  door-tests-paulina.hasenhuettl

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-paulina.hasenhuettl

  door-paulina.hasenhuettl
  gtest_main 
)

add_test(
  NAME door-tests-paulina.hasenhuettl 
  COMMAND door-tests-paulina.hasenhuettl 
)

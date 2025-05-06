add_executable(
  door-tests-anael.wirtl-moelbach

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-anael.wirtl-moelbach

  door-anael.wirtl-moelbach
  gtest_main 
)

add_test(
  NAME door-tests-anael.wirtl-moelbach
  COMMAND door-tests-anael.wirtl-moelbach
)

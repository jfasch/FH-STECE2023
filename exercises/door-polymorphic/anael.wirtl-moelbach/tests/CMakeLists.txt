add_executable(
  door-tests-polymorphic-anael.wirtl-moelbach

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
  door-tests-polymorphic-anael.wirtl-moelbach

  door-polymorphic-anael.wirtl-moelbach
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-anael.wirtl-moelbach
  COMMAND door-polymorphic-tests-anael.wirtl-moelbach
)

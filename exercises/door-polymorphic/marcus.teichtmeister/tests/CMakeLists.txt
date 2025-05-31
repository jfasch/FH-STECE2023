add_executable(
  door-tests-polymorphic-marcus.teichtmeister

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
  door-tests-polymorphic-marcus.teichtmeister

  door-polymorphic-marcus.teichtmeister
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-marcus.teichtmeister 
  COMMAND door-polymorphic-tests-marcus.teichtmeister 
)

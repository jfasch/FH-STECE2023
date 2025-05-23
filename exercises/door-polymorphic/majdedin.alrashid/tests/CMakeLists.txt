add_executable(
  door-tests-polymorphic-majdedin.alrashid

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
  door-tests-polymorphic-majdedin.alrashid

  door-polymorphic-majdedin.alrashid
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-majdedin.alrashid 
  COMMAND door-polymorphic-tests-majdedin.alrashid 
)

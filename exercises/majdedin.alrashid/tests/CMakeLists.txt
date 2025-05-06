add_executable(
  door-tests-majdedin.alrashid

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-majdedin.alrashid

  door-majdedin.alrashid
  gtest_main 
)

add_test(
  NAME door-tests-majdedin.alrashid 
  COMMAND door-tests-majdedin.alrashid 
)

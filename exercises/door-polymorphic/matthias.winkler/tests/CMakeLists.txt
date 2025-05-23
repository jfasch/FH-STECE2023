add_executable(
  door-tests-polymorphic-matthias.winkler

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
  door-tests-polymorphic-matthias.winkler

  door-polymorphic-matthias.winkler
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-matthias.winkler 
  COMMAND door-polymorphic-tests-matthias.winkler 
)

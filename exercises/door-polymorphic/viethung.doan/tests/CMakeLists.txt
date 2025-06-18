add_executable(
  door-tests-polymorphic-viethung.doan

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
  door-tests-polymorphic-viethung.doan

  door-polymorphic-viethung.doan
  gtest_main 
)

add_test(
  NAME door-polymorphic-tests-viethung.doan 
  COMMAND door-polymorphic-tests-viethung.doan 
)

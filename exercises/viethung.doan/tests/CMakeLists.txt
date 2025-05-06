add_executable(
  door-tests-viethung.doan

  motor-tests.cpp
  lightbarrier-tests.cpp
  pushbutton-tests.cpp
  door-tests.cpp
)

target_link_libraries(
  door-tests-viethung.doan

  door-viethung.doan
  gtest_main 
)

add_test(
  NAME door-tests-viethung.doan 
  COMMAND door-tests-viethung.doan 
)

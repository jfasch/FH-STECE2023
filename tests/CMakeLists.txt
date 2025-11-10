add_executable(
  door-tests

  door-tests.cpp
  timespec-tests.cpp

  pressure_mock_unit.cpp
  event-edge-detector-tests.cpp

#  input-output-switch-gpio-sysfs-tests.cpp

  inputs-tests.cpp
  outputs-tests.cpp

  adc-mock-tests.cpp
)
target_link_libraries(
  door-tests

  door
  gtest_main 
)
add_test(
  NAME door-tests 
  COMMAND door-tests
)

if (LIBGPIOD_FOUND)
  add_executable(gpio-read-value-loop gpio-read-value-loop.cpp)
  target_link_libraries(gpio-read-value-loop LIBGPIOD::LIBGPIOD)

  add_executable(motorLED-tests motorLED-tests.cpp)
  target_link_libraries(
    motorLED-tests
    door
    gtest_main
  )

  add_executable(
    input-switch-gpio-tests input-switch-gpio-tests.cpp
  )
  target_link_libraries(
    input-switch-gpio-tests
  
    door
    gtest_main
  )

  add_executable(motor-stepper-tests motor-stepper-tests.cpp)
  target_link_libraries(
    motor-stepper-tests
  
    door
    gtest_main
  )

  add_executable(
  input-output-switch-gpio-tests input-output-switch-gpio-tests.cpp
  )
  target_link_libraries(
    input-output-switch-gpio-tests
  
    door
    gtest_main
  )

else()
  message(WARNING "Skip motorLED-tests and gpio-read-value-loop because libgpiod not found")
endif()

add_executable(
  input-output-switch-gpio-sysfs-tests
  input-output-switch-gpio-sysfs-tests.cpp
)
target_link_libraries(
  input-output-switch-gpio-sysfs-tests
  door
  gtest_main
)
add_test(
  NAME input-output-switch-gpio-sysfs-tests
  COMMAND sudo input-output-switch-gpio-sysfs-tests
)

add_executable(bmp280_test bmp280-test.cpp)
add_executable(adc_ads1115_test adc-ads1115-test.cpp)
add_executable(hysteresis_hw_test hysteresis_hw_test.cpp)

target_link_libraries(
  bmp280_test

  PRIVATE
  door
  gtest_main
)
target_link_libraries(
  adc_ads1115_test

  PRIVATE
  door
  gtest_main
)

target_link_libraries(
  hysteresis_hw_test

  PRIVATE
  door
)

add_test(
  NAME bmp280_test
  COMMAND bmp280_test
)

add_test(
  NAME adc_ads1115_test
  COMMAND adc_ads1115_test
)

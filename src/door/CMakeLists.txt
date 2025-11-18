set(DOOR_FILES

  door.h
  door.cpp

  motor.h
  motor-mock.h
  motor-mock.cpp
  #motor-stepper.h
  #motor-stepper.cpp
  #motorLED.h
  #motorLED.cpp

  small_file_handling.h
  small_file_handling.cpp

  input-switch.h
  input-switch-mock.h
  input-switch-mock.cpp
  input-switch-gpio-sysfs.h
  input-switch-gpio-sysfs.cpp

  output-switch.h
  output-switch-mock.h
  output-switch-mock.cpp
  output-switch-gpio-sysfs.h
  output-switch-gpio-sysfs.cpp

  pressure-sensor-bmp280.h
  pressure-sensor-bmp280.cpp

  adc-ads1115.h
  adc-ads1115.cpp

  event-edge-detector.h
  event-edge-detector.cpp

  inputs.h
  inputs.cpp
  outputs.h
  outputs.cpp 

  analog-sensor.h
  analog-sensor-mock.h
  analog-sensor-mock.cpp
  analog-sensor-event-generator.h
  analog-sensor-event-generator.cpp

  motorLED.h 
  motorLED.cpp

)

add_subdirectory(utilities)

add_library(
  door

  ${DOOR_FILES}
)


# build information (include path) for our users
target_include_directories(
  door

  INTERFACE

  ${CMAKE_CURRENT_SOURCE_DIR}/..                       # <-- users have to e.g. say #include <door/motor.h>
)

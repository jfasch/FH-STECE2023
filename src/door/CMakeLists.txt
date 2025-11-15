set(DOOR_FILES

  door.h
  door.cpp

  timespec.h
  timespec.cpp

  motor.h
  motor-mock.h
  motor-mock.cpp
  motor-stepper.h
  motor-stepper.cpp
  motorLED.h
  motorLED.cpp

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
  
  pressure-sensor.h
  pressure-sensor-mock.h
  pressure-sensor-mock.cpp
  pressure-sensor-bmp280.h
  pressure-sensor-bmp280.cpp
  pressure-sensor-event-generator.h
  pressure-sensor-event-generator.cpp

  adc.h
  adc-mock.h
  adc-mock.cpp
  adc-ads1115.h
  adc-ads1115.cpp

  event-edge-detector.h
  event-edge-detector.cpp

  inputs.h
  inputs.cpp
  outputs.h
  outputs.cpp 

)

if (LIBGPIOD_FOUND)                                    # <-- set toplevel by find_package(LIBGPIOD)
  set(DOOR_FILES 

    ${DOOR_FILES}
    motorLED.h 
    motorLED.cpp
    motor-stepper.h
    motor-stepper.cpp
    
    output-switch-gpio.cpp
    output-switch-gpio.h
    input-switch-gpio.cpp
    input-switch-gpio.h
    )
endif()


add_library(
  door

  ${DOOR_FILES}
)

# build information (include path) for our users
target_include_directories(
  door

  PUBLIC

  ${CMAKE_CURRENT_SOURCE_DIR}/..                       # <-- users have to e.g. say #include <door/motor.h>
)

if (LIBGPIOD_FOUND)                                    # <-- set toplevel by find_package(LIBGPIOD)
  target_link_libraries(door LIBGPIOD::LIBGPIOD)
else()
  message(WARNING "door will not use libgpiod (which has not been found). note that this might lead to errors in the build process")
endif()

if (LIBGPIODCXX_FOUND)                                 # <-- set toplevel by find_package(LIBGPIODCXX)
  target_link_libraries(door LIBGPIODCXX::LIBGPIODCXX)
else()
  message(WARNING "door will not use libgpiod (which has not been found). note that this might lead to errors in the build process")
endif()

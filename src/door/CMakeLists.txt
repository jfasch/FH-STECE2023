set(DOOR_FILES

  door.h
  door.cpp

  timespec.h
  timespec.cpp

  motor.h
  motor-mock.h
  motor-mock.cpp

  light-barrier.h
  light-barrier-gpio.cpp
  light-barrier-gpio.h
  light-barrier-mock.h
  light-barrier-mock.cpp

  push-button.h
  push-button-mock.h
  push-button-mock.cpp

  inputs.h
  inputs.cpp

  event-edge-detector.h
  event-edge-detector.cpp

  outputs.h
  outputs.cpp 
  
)

if (LIBGPIOD_FOUND)                                    # <-- set toplevel by find_package(LIBGPIOD)
  set(DOOR_FILES 

    ${DOOR_FILES}
    motorLED.h 
    motorLED.cpp
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

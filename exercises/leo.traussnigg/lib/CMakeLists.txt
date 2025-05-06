ADD_LIBRARY(
  door-leo.traussnigg

  door.h
  door.cpp

  motor.h
  motor.cpp

  light-barrier.h
  light-barrier.cpp

  push-button.h
  push-button.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-leo.traussnigg

  PUBLIC
  .
)

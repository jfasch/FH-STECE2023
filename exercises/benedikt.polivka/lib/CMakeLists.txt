ADD_LIBRARY(
  door-benedikt.polivka

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
  door-benedikt.polivka

  PUBLIC
  .
)

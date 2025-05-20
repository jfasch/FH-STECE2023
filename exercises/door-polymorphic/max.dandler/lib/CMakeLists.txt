ADD_LIBRARY(
  door-polymorphic-max.dandler

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
  door-polymorphic-max.dandler

  PUBLIC
  .
)

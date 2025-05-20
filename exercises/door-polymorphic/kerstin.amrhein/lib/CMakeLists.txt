ADD_LIBRARY(
  door-polymorphic-kerstin.amrhein

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
  door-polymorphic-kerstin.amrhein

  PUBLIC
  .
)

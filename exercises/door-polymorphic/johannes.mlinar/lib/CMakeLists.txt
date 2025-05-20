ADD_LIBRARY(
  door-polymorphic-johannes.mlinar

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
  door-polymorphic-johannes.mlinar

  PUBLIC
  .
)

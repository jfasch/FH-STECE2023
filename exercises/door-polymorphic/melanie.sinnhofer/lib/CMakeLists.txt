ADD_LIBRARY(
  door-polymorphic-melanie.sinnhofer

  door.h
  door.cpp

  motor.h
  motor-mock.cpp

  light-barrier.h
  light-barrier.cpp

  push-button.h
  push-button.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-melanie.sinnhofer

  PUBLIC
  .
)

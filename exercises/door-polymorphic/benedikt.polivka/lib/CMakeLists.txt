ADD_LIBRARY(
  door-polymorphic-benedikt.polivka

  door.h
  door.cpp

  motor.h
  motor.cpp

  motor-mock.h
  motor-mock.cpp

  light-barrier.h
  light-barrier.cpp

  light-barrier-mock.h
  light-barrier-mock.cpp

  push-button.h
  push-button.cpp

  push-button-mock.h
  push-button-mock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-benedikt.polivka

  PUBLIC
  .
)

ADD_LIBRARY(
  door-polymorphic-joerg.faschingbauer

  door.h
  door.cpp

  motor.h
  motor-mock.h
  motor-mock.cpp

  light-barrier.h
  light-barrier-mock.h
  light-barrier-mock.cpp

  push-button.h
  push-button-mock.h
  push-button-mock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-joerg.faschingbauer

  PUBLIC
  .
)

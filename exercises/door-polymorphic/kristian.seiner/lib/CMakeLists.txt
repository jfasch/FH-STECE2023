ADD_LIBRARY(
  door-polymorphic-kristian.seiner

  door.h
  door.cpp

  motor-mock.h
  motor-mock.cpp
  motor.h

  light-barrier-mock.h
  light-barrier-mock.cpp
  light-barrier.h

  push-button-mock.h
  push-button-mock.cpp
  push-button.h
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-kristian.seiner

  PUBLIC
  .
)

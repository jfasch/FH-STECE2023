ADD_LIBRARY(
  door-polymorphic-paul.bichl

  door.h
  door.cpp

  motor.h
  motor-mock.h
  motor-mock.cpp

  light-barrier.h
  light-barrier-mock.h
  light-barrier-mock.cpp

  push-button.h
  push-button.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-paul.bichl

  PUBLIC
  .
)

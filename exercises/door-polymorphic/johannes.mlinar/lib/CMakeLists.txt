ADD_LIBRARY(
  door-polymorphic-johannes.mlinar

  door.h
  door.cpp

  motor.h
  motorMock.cpp

  light-barrier.h
  light-barrierMock.h
  light-barrierMock.cpp
  push-button.h
  push-buttonMock.h
  push-buttonMock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-johannes.mlinar

  PUBLIC
  .
)

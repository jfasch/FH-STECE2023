ADD_LIBRARY(
  door-polymorphic-maximilian.hofstaetter

  door.h
  door.cpp

  motor-Mock.h
  motor.h
  motor-Mock.cpp

  light-barrier-Mock.h
  light-barrier.h
  light-barrier-Mock.cpp

  push-button-Mock.h
  push-button.h
  push-button-Mock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-maximilian.hofstaetter

  PUBLIC
  .
)

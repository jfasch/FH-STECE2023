ADD_LIBRARY(
  door-polymorphic-viethung.doan

  door.h
  door.cpp

  motor.h
  motor-mock.cpp

  light-barrier.h
  light-barrier-mock.cpp

  push-button.h
  push-button-mock.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-viethung.doan

  PUBLIC
  .
)

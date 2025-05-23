ADD_LIBRARY(
  door-polymorphic-lorenz.kristl

  door.h
  door.cpp

  motor.h
  motor.cpp

  light-barrier.h
  light-barrier.cpp

  push-button.h
  push-button.cpp

  motor-mock.h
  motor-mock.cpp

  light-barrier-mock.h
  light-barrier-mock.cpp

  push-button-mock.h
  push-button-mock.cpp

)

TARGET_INCLUDE_DIRECTORIES(
  door-polymorphic-lorenz.kristl

  PUBLIC
  .
)

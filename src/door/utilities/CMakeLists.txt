add_library(
    utilities

    timespec.h
    timespec.cpp
    eventloop.h
    eventloop.cpp
)

target_include_directories(
    utilities
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../..
)

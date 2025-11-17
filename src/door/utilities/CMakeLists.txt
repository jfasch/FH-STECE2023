set(UTILITIES_FILES
    timespec.h
    timespec.cpp
)

add_library(
    utilities
    ${UTILITIES_FILES}

)


target_include_directories(
    utilities
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../..
)


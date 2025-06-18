add_executable(blink blink.cpp)

add_subdirectory(point-c)
add_subdirectory(point-c++)

add_subdirectory(enum-class)
add_executable(dtor dtor.cpp)

add_subdirectory(oo-c)
add_subdirectory(interfaces)

add_executable(assignment assignment.cpp)
# add_executable(nullptr nullptr.cpp)
add_executable(auto auto.cpp)

add_executable(event event.cpp)

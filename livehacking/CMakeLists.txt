add_executable(blink blink.cpp)

add_subdirectory(point-c)
add_subdirectory(point-c++)

add_subdirectory(enum-class)
add_executable(auto auto.cpp)
add_executable(dtor dtor.cpp)
add_subdirectory(polymorphic-data-logger)

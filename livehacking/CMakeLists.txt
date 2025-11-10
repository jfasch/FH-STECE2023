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

# add_executable(str-segfault-maybe str-segfault-maybe.cpp)

add_executable(2025-10-20 2025-10-20.cpp)

add_executable(uninitialized-memory uninitialized-memory.cpp)

add_executable(sizeof sizeof.cpp)

add_executable(signals signals.cpp)
target_compile_options(signals PRIVATE -Wno-div-by-zero)


find_package(GTest REQUIRED)

add_executable(run-door-leo.traussnigg run-door.cpp)
target_link_libraries(run-door-leo.traussnigg door-leo.traussnigg)

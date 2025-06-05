cmake_minimum_required(VERSION 3.16)
project(FH-STECE2023)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -g3 -Wall -Werror")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
find_package(LIBGPIODCXX)
if (NOT LIBGPIODCXX_FOUND)
  message(WARNING "libgpiodcxx not found (some code will not be built)")
endif()

add_subdirectory(bin)
add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(livehacking)
# add_subdirectory(exercises)
add_subdirectory(googletest)

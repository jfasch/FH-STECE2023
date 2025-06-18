# Usage:
#
# if (LIBGPIOD_FOUND)
#    target_link_libraries(MyTarget LIBGPIOD::LIBGPIOD)
# endif()

find_path(LIBGPIOD_INCLUDE_DIR gpiod.h)
find_library(LIBGPIOD_LIBRARY NAMES gpiod)
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
  LIBGPIOD
  FOUND_VAR LIBGPIOD_FOUND
  REQUIRED_VARS LIBGPIOD_LIBRARY LIBGPIOD_INCLUDE_DIR
)

message(STATUS "libgpiod include dir: ${LIBGPIOD_INCLUDE_DIR}")
message(STATUS "libgpiod: ${LIBGPIOD_LIBRARY}")
set(LIBGPIOD_LIBRARIES ${LIBGPIOD_LIBRARY})

mark_as_advanced(LIBGPIOD_LIBRARY LIBGPIOD_INCLUDE_DIR)

add_library(LIBGPIOD::LIBGPIOD INTERFACE IMPORTED)
target_link_libraries(LIBGPIOD::LIBGPIOD INTERFACE ${LIBGPIOD_LIBRARIES})
target_include_directories(LIBGPIOD::LIBGPIOD INTERFACE ${LIBGPIOD_INCLUDE_DIR})

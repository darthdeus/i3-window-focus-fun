cmake_minimum_required(VERSION 3.10)
project(sdl_window C)

set(CMAKE_C_STANDARD 11)

set(SDL_PIPEWIRE OFF)

add_executable(sdlwin_cmake sdlwin.c)

# --------------------
# on arch uses 2.32.54 which is sdl2-compat, which is SDL3, broken

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

# --------------------
# this DOES NOT grab focus

# add_subdirectory(vendor/SDL2-2.30.4 EXCLUDE_FROM_ALL)
#
# target_include_directories(
#   sdlwin_cmake PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-2.30.4/include
# )

# --------------------
# this DOES NOT grab focus either

# add_subdirectory(vendor/SDL2-2.32.4 EXCLUDE_FROM_ALL)
#
# target_include_directories(
#   sdlwin_cmake PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-2.32.4/include
# )

# --------------------
# real SDL2, works with all versions

# add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
#
# target_include_directories(
#   sdlwin_cmake PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/include
# )


# --------------------
# THIS IS THE REAL ASSHOLE that doesn't work

add_subdirectory(vendor/sdl2-compat EXCLUDE_FROM_ALL)

target_include_directories(
  sdlwin_cmake PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/vendor/sdl2-compat/include
)

# --------------------


target_link_libraries(sdlwin_cmake PRIVATE SDL2::SDL2)


# --------------------

# add_subdirectory(vendor/SDL3-3.2.10 EXCLUDE_FROM_ALL)
#
# target_include_directories(
#   sdlwin_cmake PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL3-3.2.10/include
# )

# --------------------

# target_link_libraries(sdlwin_cmake PRIVATE SDL3::SDL3)


# # SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
# if(TARGET SDL2::SDL2main)
#   # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
#   target_link_libraries(sdlwin_cmake PRIVATE SDL2::SDL2main)
# endif()

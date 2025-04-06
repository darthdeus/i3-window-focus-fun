cmake_minimum_required(VERSION 3.10)
project(sdl_window C)

# Set C standard
set(CMAKE_C_STANDARD 11)


set(SDL_PIPEWIRE OFF)


# Find SDL2 package
# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(vendor/SDL2-2.30.4 EXCLUDE_FROM_ALL)

# Add executable
add_executable(sdlwin_cmake sdlwin.c)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
  # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
  target_link_libraries(sdlwin_cmake PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(sdlwin_cmake PRIVATE SDL2::SDL2)

target_include_directories(sdlwin_cmake PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-2.30.4/include
)


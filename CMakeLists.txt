cmake_minimum_required(VERSION 3.10)

project(UFOCells)

option(HAS_TERMINAL "Show a terminal window for STDOUT/STDERR" ON)

# Set C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(
    SRC
    src/ufo/animation.cpp
    src/ufo/assets.cpp
    src/ufo/button.cpp
    src/ufo/cell_actor.cpp
    src/ufo/dynamic_solid.cpp
    src/ufo/collision_utils.cpp
    src/ufo/colour_utils.cpp
    src/ufo/misc_math.cpp
    src/ufo/rect.cpp
    src/ufo/file_utils.cpp
    src/ufo/camera.cpp
    src/ufo/mouse_control.cpp
    src/ufo/game.cpp
    src/ufo/layer.cpp
    src/ufo/layer_actor.cpp
    src/ufo/layer_background.cpp
    src/ufo/layer_terrain.cpp
    src/ufo/layer_solid.cpp
    src/program/ufo_global.cpp
    src/scripting/api.cpp
    src/squirrel/squirrel_error.cpp
    src/ufo/timer.cpp
    src/scripting_utils/squirrel_interface.cpp
    src/scripting/wrapper.cpp
    src/ufo/player_ray.cpp
    src/ufo/level.cpp
    src/ufo/level_loader.cpp
    src/ufo/stack_based_state_machine.cpp
    src/ufo/stack_based_state.cpp
    src/ufo/json_interface.cpp
    external/cJSON.c
)

include(ExternalProject)
include(cmake/ProvideSquirrel.cmake)
include(cmake/BuildMiniswigWrapper.cmake)

add_library(UFOCells STATIC ${SRC})
target_include_directories(UFOCells PUBLIC src)


#include(cmake/BuildProgramFile.cmake)

target_link_libraries(UFOCells PUBLIC LibSquirrel)
target_link_libraries(UFOCells PUBLIC LibSqstdlib)

# OpenGL
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
target_link_libraries(UFOCells PUBLIC OpenGL::GL)

# X11
find_package(X11 REQUIRED)
target_link_libraries(UFOCells PUBLIC X11::X11)

include_directories(${X11_INCLUDE_DIRS})

# Threads
find_package(Threads REQUIRED)
target_link_libraries(UFOCells PUBLIC Threads::Threads)
include_directories(${Threads_INCLUDE_DIRS})

find_package(PNG REQUIRED)
target_link_libraries(UFOCells PUBLIC PNG::PNG)
include_directories(${PNG_INCLUDE_DIRS})

# stdc++fs
target_link_libraries(UFOCells PUBLIC stdc++fs)

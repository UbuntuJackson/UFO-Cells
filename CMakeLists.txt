cmake_minimum_required(VERSION 3.10)

project(UFOCells)

option(HAS_TERMINAL "Show a terminal window for STDOUT/STDERR" ON)

# Set C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required libraries
find_package(CURL REQUIRED)
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)

set(
    SRC
    src/ufo/actor.cpp
    src/ufo/animation.cpp
    src/ufo/assets.cpp
    src/ufo/asset_manager.cpp
    src/ufo/button.cpp
    src/ufo/collision_body.cpp
    src/ufo/dynamic_solid.cpp
    src/ufo/collision_utils.cpp
    src/ufo/colour_utils.cpp
    src/ufo/math_misc.cpp
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
    src/ufo/timer.cpp
    src/ufo/level.cpp
    src/ufo/level_loader.cpp
    src/ufo/stack_based_state_machine.cpp
    src/ufo/stack_based_state.cpp
    src/ufo/json_interface.cpp
    external/cJSON.c
    src/ufo/ray_vs_ray_2.cpp
    src/ufo/ray2.cpp
    src/ufo/file.cpp
    src/ufo/scene.cpp
    src/ufo/scene_system.cpp
    src/ufo/component.cpp
)

# Add the library
add_library(UFOCells STATIC ${SRC})
target_include_directories(UFOCells PUBLIC src)
target_include_directories(UFOCells PUBLIC external)

# Link libraries
target_link_libraries(UFOCells PUBLIC
    CURL::libcurl
    PNG::PNG
    ZLIB::ZLIB
)

# OpenGL
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
target_include_directories(UFOCells PUBLIC ${OpenGL_INCLUDE_DIRS})
target_link_libraries(UFOCells PUBLIC OpenGL::GL)

# X11
if(NOT WIN32)
    find_package(X11 REQUIRED)
    if(NOT X11_FOUND)
        message(FATAL_ERROR "X11 not found. Please install X11 development libraries.")
    endif()
    target_include_directories(UFOCells PUBLIC ${X11_INCLUDE_DIR})
    target_link_libraries(UFOCells PUBLIC X11::X11)
endif()

# Threads
find_package(Threads REQUIRED)
target_link_libraries(UFOCells PUBLIC Threads::Threads)

# stdc++fs
target_compile_features(UFOCells PUBLIC cxx_std_17)

cmake_minimum_required(VERSION 3.10)

project(UFOCells)

option(HAS_TERMINAL "Show a terminal window for STDOUT/STDERR" ON)

#Packaging debug and release
#set(CMAKE_DEBUG_POSTFIX d)

# Set C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# output executable basename
set(OutputExecutable "${CMAKE_PROJECT_NAME}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
#include(cmake/BuildProgramFile.cmake)
include(ExternalProject)
include(cmake/ProvideSquirrel.cmake)
include(cmake/BuildMiniswigWrapper.cmake)


# Source Files are Curated Here
file(
    GLOB SRCFILES
    src/ufo/assets.cpp
    src/ufo/cell_actor.cpp
    src/ufo/collision_utils.cpp
    src/ufo/colour_utils.cpp
    src/ufo/misc_math.cpp
    src/ufo/rect.cpp
    src/ufo/cellmap.cpp
    src/ufo/file_utils.cpp
    src/ufo/camera.cpp
    src/ufo/mouse_control.cpp
    src/ufo/state.cpp
    src/ufo/game.cpp
    src/program/program.cpp
    src/program/main.cpp
    src/program/ufo_global.cpp
    games/dummy_test/*.cpp
    src/scripting/api.cpp
    src/squirrel/squirrel_error.cpp
    src/scripting/wrapper.cpp
    external/cJSON.c
)

# Executable aka binary output
add_executable(UFOCells ${SRCFILES})

#Packaging debug and release
#set_target_properties(UFOCells PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

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

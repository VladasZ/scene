cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(scene)

add_subdirectory(source/scene)
add_subdirectory(source/scene_lib)
add_subdirectory(source/geometry)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(scene_lib)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

conan_target_link_libraries(${PROJECT_NAME})

link_project(geometry)

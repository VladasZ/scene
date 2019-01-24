cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(scene)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(scene_lib)
link_project(geometry)

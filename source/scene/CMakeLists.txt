cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(scene)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

conan_target_link_libraries(${PROJECT_NAME})

link_project(scene_lib)
link_project(geometry)

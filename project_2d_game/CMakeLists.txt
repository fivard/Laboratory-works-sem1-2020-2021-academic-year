cmake_minimum_required(VERSION 3.15)
project(project_2d_game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 COMPONENTS window system graphics audio)

add_executable(project_2d_game main.cpp)


target_link_libraries(project_2d_game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
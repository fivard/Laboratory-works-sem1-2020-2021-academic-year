cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 COMPONENTS window system graphics sound)

add_executable(project main.cpp)

target_link_libraries(project ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
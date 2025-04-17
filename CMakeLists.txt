cmake_minimum_required(VERSION 3.20)

project(Snake VERSION 1.1 LANGUAGES CXX)

option(BUILD_TESTS "build unit tests" OFF)

include_directories(${CMAKE_SOURCE_DIR})

message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


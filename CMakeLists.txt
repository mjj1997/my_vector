cmake_minimum_required(VERSION 3.20)

project(MyVector VERSION 2.0 LANGUAGES CXX)

option(BUILD_MYVECTOR_SHARED_LIBS "build MyVector shared library" ON)
option(BUILD_MYVECTOR_STATIC_LIBS "build MyVector static library" ON)

option(BUILD_EXAMPLES "build examples" OFF)
option(BUILD_TESTS "build unit tests" OFF)

include_directories(${CMAKE_SOURCE_DIR})

message(STATUS "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


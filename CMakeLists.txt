cmake_minimum_required(VERSION 3.10)

# Project name
project(CyForgeDS CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Warning flags for g++
add_compile_options(-Wall -Wextra -pedantic)

# Debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Source files
set(SOURCES
    tests/cpp/ArrayList_test.cpp
    tests/cpp/LLNode_test.cpp
    tests/cpp/LinkBasedList_test.cpp
)

# Build executables
add_executable(arraylist_test tests/cpp/ArrayList_test.cpp)
add_executable(llnode_test tests/cpp/LLNode_test.cpp)
add_executable(linkbasedlist_test tests/cpp/LinkBasedList_test.cpp)

target_include_directories(arraylist_test PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(llnode_test PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(linkbasedlist_test PRIVATE ${CMAKE_SOURCE_DIR})


# print useful info
message(STATUS "Building CyForgeDS")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")

cmake_minimum_required(VERSION 3.15)
project(JavaSafeCpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compiler warnings
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)

# Add include directories
include_directories(${SRC_DIR})

# Find all source files for the compiler (excluding main.cpp)
file(GLOB_RECURSE COMPILER_SOURCES 
    ${SRC_DIR}/lexer/*.cpp
    ${SRC_DIR}/parser/*.cpp
    ${SRC_DIR}/semantic/*.cpp
    ${SRC_DIR}/bytecode/*.cpp
    ${SRC_DIR}/vm/*.cpp
    ${SRC_DIR}/common/*.cpp
)

# Compiler Library
add_library(jscpp_lib STATIC ${COMPILER_SOURCES})

# Main executable
add_executable(jscpp ${SRC_DIR}/main.cpp)
target_link_libraries(jscpp PRIVATE jscpp_lib)

# Tests
enable_testing()
# We will add tests later using a simple custom framework or just CTest

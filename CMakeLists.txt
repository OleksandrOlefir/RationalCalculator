# Minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Project declaration
project(teletactica LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(TEST_BINARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

# Include headers from "include" directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Main executable
add_executable(teletactica
    src/teletactica.cpp
    src/main.cpp
)

# Set the output location for the main binary
set_target_properties(teletactica PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# Enable testing
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Unit test executable
add_executable(unit_tests
    tests/test_teletactica.cpp
    src/teletactica.cpp
)

# Set the output location for the test binary
set_target_properties(unit_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_OUTPUT_DIRECTORY}
)

# Link test binary with GoogleTest
target_link_libraries(unit_tests PRIVATE GTest::gtest_main)

# Run test discovery
gtest_discover_tests(unit_tests)

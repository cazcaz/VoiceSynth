# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(voice_synth)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Automatically detect source files in "source" directory
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/source/*.cpp)

# Remove the main.cpp file from the source files
list(REMOVE_ITEM SRC_FILES "${PROJECT_SOURCE_DIR}/source/main.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/source/main.cpp ${SRC_FILES}) 

# Add Catch2 as a subdirectory if it exists
if(EXISTS "${PROJECT_SOURCE_DIR}/catch2/CMakeLists.txt")
    add_subdirectory(catch2)
endif()

# Enable testing
enable_testing()

# Add a new directory for unit tests
file(GLOB_RECURSE TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/unit_tests/*.cpp)
set(Catch2_DIR "${PROJECT_SOURCE_DIR}/catch2")

# These tests can use the Catch2-provided main
add_executable(unit_tests ${TEST_SRC_FILES} ${SRC_FILES})
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

# Add tests to the project
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_test(NAME ${_test_name} COMMAND unit_tests)
endforeach()

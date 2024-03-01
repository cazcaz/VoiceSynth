# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(voice_synth)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Automatically detect source files in "source" directory
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/source/*.cpp)

# Automatically detect header files in "header" directory
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/header/*.h)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
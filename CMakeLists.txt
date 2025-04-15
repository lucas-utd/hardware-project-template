cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(HardwareProjectTemplate
    LANGUAGES CXX
    VERSION 1.0
    DESCRIPTION "A template for a hardware project using CMake"
)

# Set the C++ standard to C++23
# and enable C++23 features
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src bin)

# Enable testing
enable_testing()
add_subdirectory(test)
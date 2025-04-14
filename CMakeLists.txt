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

# Find and include the SFML library
find_path(BEXT_DI_INCLUDE_DIRS "boost/di.hpp")
if (DEFINED BEXT_DI_INCLUDE_DIRS)
    include_directories(${BEXT_DI_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "bext-di not found")
endif()

# Find the nlohmann/json library
find_package(nlohmann_json CONFIG REQUIRED)
if (DEFINED nlohmann_json_FOUND)
    include_directories(${nlohmann_json_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "nlohmann/json not found")
endif()

# Find and include the magic_enum library
find_package(magic_enum CONFIG REQUIRED)
if (DEFINED magic_enum_FOUND)
    include_directories(${magic_enum_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "magic_enum not found")
endif()
    
# Find and include the stduuid library
find_package(stduuid CONFIG REQUIRED)
if (DEFINED stduuid_FOUND)
    include_directories(${stduuid_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "stduuid not found")
endif()

# Add the source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add the executable target
add_executable(HardwareProject ${SOURCES})

# Add the include directories for the target
target_include_directories(HardwareProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the compiler flags
if (MSVC)
    target_compile_options(HardwareProject PRIVATE
        /W4
        /permissive-
        /WX
    )
else()
    target_compile_options(HardwareProject PRIVATE
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
endif()

# Link the nlohmann-json and magic enum libraries
target_link_libraries(HardwareProject magic_enum::magic_enum nlohmann_json::nlohmann_json)

# Set the output directory for the executable
set_target_properties(HardwareProject PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    OUTPUT_NAME "MyHardwareProject"  # Set a custom output name for the executable
    VERSION 1.0  # Set the version for the executable
    SOVERSION 1  # Set the shared object version for the executable
    CXX_STANDARD 23  # Ensure the C++ standard is set for the target
    CXX_STANDARD_REQUIRED YES  # Require the specified C++ standard
    CXX_EXTENSIONS NO  # Disable compiler-specific extensions
)

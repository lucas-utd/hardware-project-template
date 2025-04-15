add_subdirectory(Algo)
add_subdirectory(Consumer)
add_subdirectory(Hardware)
add_subdirectory(Models)
add_subdirectory(Utils)


# Add the executable target
add_executable(HardwareProject main.cpp)

# Add the include directories for the target
# target_include_directories(HardwareProject PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

# Set the compiler flags
if (DEFINED MSVC)
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
target_link_libraries(HardwareProject
    Models
    Utils
    Consumer
    Algo
    Hardware
)

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

# # Enable testing
# enable_testing()

# # Add test executable
# add_executable(MyTests tests/test_main.cpp)

# # Link with GTest
# find_package(GTest CONFIG REQUIRED)
# if (NOT GTest_FOUND)
#     message(FATAL_ERROR "GTest not found")
# endif()
# target_link_libraries(MyTests PRIVATE GTest::gtest GTest::gtest_main)

# # Discover tests
# include(GoogleTest)
# gtest_discover_tests(MyTests)
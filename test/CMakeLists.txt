
# Add test executable
add_executable(MyTests test_main.cpp)

# Link with GTest
find_package(GTest CONFIG REQUIRED)
if (NOT GTest_FOUND)
    message(FATAL_ERROR "GTest not found")
endif()
target_link_libraries(MyTests PRIVATE GTest::gtest GTest::gtest_main)

# Discover tests
include(GoogleTest)
gtest_discover_tests(MyTests)
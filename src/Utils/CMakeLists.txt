
# Find and include the stduuid library
find_package(stduuid CONFIG REQUIRED)
if (NOT stduuid_FOUND)
    message(FATAL_ERROR "stduuid not found")
endif()

add_library(
    Utils
    OBJECT
    uuidUtil.cpp
)

target_link_libraries(Utils PRIVATE stduuid)
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
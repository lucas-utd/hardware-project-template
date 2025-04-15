add_library(
    Hardware
    OBJECT
    HardwareDevice.cpp
)
target_include_directories(Hardware PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Hardware PUBLIC Models Algo Consumer Utils)
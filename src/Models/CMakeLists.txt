add_library(
    Models
    OBJECT
    SamplePacket.cpp
)
target_include_directories(Models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
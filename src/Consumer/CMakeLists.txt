add_library(
    Consumer
    OBJECT
    Client.cpp
)
target_include_directories(Consumer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Consumer PUBLIC Models)
add_library(
    Algo
    OBJECT
    AlgorithmInstance.cpp
)
target_include_directories(Algo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Algo PUBLIC Models)
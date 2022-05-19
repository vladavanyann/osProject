project(ResponseRepository)

add_library(
    ResponseRepository SHARED

    ResponseRepository.h
    ResponseRepository.cpp

)

target_link_libraries(ResponseRepository)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")


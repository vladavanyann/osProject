cmake_minimum_required(VERSION 3.16)
project(osProject_ VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories("RequestRepository")
include_directories("ResponseRepository")


add_executable(${PROJECT_NAME} CrawlerMain.cpp)

add_subdirectory(RequestRepository)
add_subdirectory(ResponseRepository)



set_target_properties(RequestRepository PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/RequestRepository/libRequestRepository.so"
        )

set_target_properties(ResponseRepository PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ResponseRepository/libResponseRepository.so"
        )


target_link_libraries(${PROJECT_NAME} RequestRepository ResponseRepository)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
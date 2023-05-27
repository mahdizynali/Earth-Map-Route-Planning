cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project (mazePlanner)

set( NAME_SRC
    src/main.cpp  
    src/mapping.cpp
)

set( NAME_HEADERS        
    include/mapping.hpp 
    include/planning.hpp 
)

find_package(OpenCV REQUIRED )

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


add_executable(mazePlanner ${NAME_SRC} ${NAME_HEADERS})

target_link_libraries(mazePlanner PRIVATE ${OpenCV_LIBS})
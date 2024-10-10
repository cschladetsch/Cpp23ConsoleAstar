cmake_minimum_required(VERSION 3.12)
project(IDA_Star)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the directory containing rang.hpp to the include path
include_directories(${CMAKE_SOURCE_DIR})

add_executable(ida_star
    main.cpp
    ida_star.cpp
    visualisation.cpp
)

target_include_directories(ida_star PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

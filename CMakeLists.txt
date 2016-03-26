cmake_minimum_required(VERSION 2.8.12)

project(MHackathon)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Main Main.cpp)
target_link_libraries(Main ${OpenCV_LIBS})

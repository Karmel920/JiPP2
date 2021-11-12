cmake_minimum_required(VERSION 3.16)

project(e1NoCopyingConstructor)
include_directories(include)

add_executable(CopyingConstructor src/main.cpp src/Point.cpp src/Vehicle.cpp)
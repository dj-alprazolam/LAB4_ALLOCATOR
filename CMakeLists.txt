cmake_minimum_required(VERSION 3.30.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 
project(LAB4 VERSION 0.1.0 LANGUAGES C CXX)

find_package(fmt REQUIRED)

include_directories(include)
add_executable(LAB4 main.cpp)
target_link_libraries(LAB4 PRIVATE fmt::fmt)

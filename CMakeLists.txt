cmake_minimum_required(VERSION 3.10)
project(reproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(reproject
    src/main.cpp
    src/reproject.cpp
)

target_include_directories(reproject PRIVATE ${CMAKE_SOURCE_DIR}/include)

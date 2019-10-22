cmake_minimum_required(VERSION 3.9)

project(lista) 
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lista
    main.cpp
)


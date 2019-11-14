set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_minimum_required(VERSION 3.11.2)

project(MyGoF CXX)

include(./cmake/utility.cmake)

set(module_name gof)

ADD_SUBDIRS()

set(CMAKE_C_COMPILER "/usr/local/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_minimum_required(VERSION 3.11.2)

project(MyGoF CXX)


set(module_name gof)
file(GLOB file_list *)

foreach(child IN LISTS file_list)
  if (IS_DIRECTORY ${child})
    if (EXISTS ${child}/CMakeLists.txt)
      message("subdir : ${child}")
      add_subdirectory(${child})
    endif()
  endif()
endforeach()

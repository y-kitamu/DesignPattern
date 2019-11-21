set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_minimum_required(VERSION 3.11.2)

project(MyGoF CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglog -lprofiler")

include(./cmake/utility.cmake)

set(EXTERNAL_LIBS "" CACHE INTERNAL "")

if (EXISTS "/home/kitamura/lib/boost_1_67_0")
  set(BOOST_ROOT "/home/kitamura/lib/boost_1_67_0")
elseif (EXISTS "/home/kitamura/lib/boost/")
  set(BOOST_ROOT "/home/kitamura/lib/boost")
endif()
# message("BOOST_ROOT : ${BOOST_ROOT}")
find_package(Boost REQUIRED COMPONENTS system filesystem)
set(EXTERNAL_LIBS ${EXTERNAL_LIBS} Boost::system Boost::filesystem CACHE INTERNAL "")

set(module_name gof)

ADD_SUBDIRS()

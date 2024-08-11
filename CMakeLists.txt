cmake_minimum_required(VERSION 2.8.0)

project(RGFdemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(GDB "GDB ON or OFF" OFF)

if(GDB)
    message(WARNING "build on debug, GDB on")
    set(CMAKE_BUILD_TYPE "Debug")  # 定义编译类型
    set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb") # 定义Debug编译参数
else()
    message(WARNING "build on release, GDB off")
    set(CMAKE_BUILD_TYPE "Release")  # 定义编译类型
    set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # 定义Release编译参数
endif()

file(GLOB RGF_SRC "RGFlib/*.cc")
file(GLOB RGF_INC "RGFlib/*.h")
message("libRGF source file list ${RGF_SRC}")
message("libRGF include file list ${RGF_INC}")

include_directories(
    RGFlib/
)

add_library(RGF SHARED
    ${RGF_SRC}
)
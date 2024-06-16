# This file is used to generate the makefile for the project.

cmake_minimum_required(VERSION 3.10)
project(test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 遍历 src 目录下所有 .c 文件
# 并将其加入 SRCS 列表
file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB LIB_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/lib_src/*.c)
message("SRCS: ${SRCS}")
message("LIB_SRCS: ${LIB_SRCS}")

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# add_library(add SHARED ${LIB_SRCS})

# 链接静态库
# 指定libadd.a的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
link_libraries(libadd.a)

# 链接动态库
# 指定 libadd.so 的路径
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
# link_libraries(libadd.so)

add_executable(test ${SRCS})
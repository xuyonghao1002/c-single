cmake_minimum_required(VERSION 3.0)
project(SORTLIB)

include_directories(${HEAD_PATH})
aux_source_directory(./ SRCS)
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
add_library(${SORT_LIB} SHARED ${SRCS})
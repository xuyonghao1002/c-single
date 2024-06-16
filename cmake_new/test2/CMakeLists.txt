cmake_minimum_required(VERSION 3.0)
project(sorttest)

aux_source_directory(./ SRCS)
include_directories(${HEAD_PATH})

link_directories(${LIB_PATH})

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
add_executable(${APP_NAME_2} ${SRCS})

target_link_libraries(${APP_NAME_2} ${SORT_LIB})
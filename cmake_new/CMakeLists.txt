cmake_minimum_required(VERSION 3.0)
project(test)

# 定义变量
set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXEC_PATH ${PROJECT_SOURCE_DIR}/bin)
set(HEAD_PATH ${PROJECT_SOURCE_DIR}/include)
message("LIB_PATH: ${LIB_PATH}")
message("EXEC_PATH: ${EXEC_PATH}")
message("HEAD_PATH: ${HEAD_PATH}")

set(CALC_LIB calc)
set(SORT_LIB sort)

set(APP_NAME_1 test1)
set(APP_NAME_2 test2)

add_subdirectory(calc)
add_subdirectory(sort)
add_subdirectory(test1)
add_subdirectory(test2)
cmake_minimum_required(VERSION 3.17)
project(LS23 C)

set(CMAKE_C_STANDARD 99)
#系统内置变量
message("-------------")
MESSAGE("=============")
#取内置变量   LS23 + _SOURCE_DIR
message(STATUS,"-----------",${LS23_SOURCE_DIR})

# 系统内置变量

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

message("build  "+ ${PROJECT_BINARY_DIR})

include_directories(
        include
)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#系统变量  声明自己变量
set(SRC_LIST main.c include/test1.c)
#默认是生成静态库
add_library(LS23 STATIC ${SRC_LIST})
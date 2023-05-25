cmake_minimum_required(VERSION 3.17)
project(LS21 C)

set(CMAKE_C_STANDARD 99)
#系统内置变量
message("-------------")
MESSAGE("=============")
#取内置变量   LS21 + _SOURCE_DIR
message(STATUS,"-----------",${LS21_SOURCE_DIR})

# 系统内置变量



message("build  "+ ${PROJECT_BINARY_DIR})

include_directories(
        include
)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#系统变量  声明自己变量（不能用逗号）
set(SRC_LIST main.c include/test1.c)
#默认是生成静态库
#add_library(LS21 ${SRC_LIST})
#动态库（是基于静态库生成的，先生成静态库，再生成动态库）
#add_library(LS21 SHARED  ${SRC_LIST})
add_executable(LS21 ${SRC_LIST})
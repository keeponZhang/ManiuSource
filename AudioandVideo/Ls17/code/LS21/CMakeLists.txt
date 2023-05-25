cmake_minimum_required(VERSION 3.17)
project(LS21 C)

set(CMAKE_C_STANDARD 99)
#系统内置变量
message("-------------")
MESSAGE("=============")
#取内置变量   LS21 + _SOURCE_DIR
message(STATUS,"-----------",${LS21_SOURCE_DIR})

# 系统内置变量

#set()

message("build  "+ ${PROJECT_BINARY_DIR})

#把整个文件夹包含进来
include_directories(
        include
)
add_executable(LS21 main.c include/test1.c)
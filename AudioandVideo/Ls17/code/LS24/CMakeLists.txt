cmake_minimum_required(VERSION 3.17)
project(LS24 C)

set(CMAKE_C_STANDARD 99)
#头文件必须导入
include_directories(${PROJECT_SOURCE_DIR}/include)


#只是定义一个变量   staticFiled 定义了一个变量  类型 是静态的   作用  导入库
add_library(maniu  STATIC IMPORTED )
#指定头文件目录位置

set_property(TARGET maniu PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/libLS23.a)
add_executable(LS24 main.c)
#链接
target_link_libraries(LS24 maniu)
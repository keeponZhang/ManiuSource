cmake_minimum_required(VERSION 3.4.1)
add_library( # Sets the name of the library.
             native-lib
             SHARED
             native-lib.cpp
#        a  组件化  .so 插件化
#        )
        #   log-lib代表变量
find_library( # Sets the name of the path variable.
              log-lib
              log )
        #  ${log-lib}代表取变量
target_link_libraries( # Specifies the target library.
                       native-lib
                       ${log-lib} )
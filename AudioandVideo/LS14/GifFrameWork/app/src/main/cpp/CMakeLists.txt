# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

add_library(
             native-lib
             SHARED

             native-lib.cpp
        dgif_lib.c
        gifalloc.c)


find_library(  log-lib
              log )
find_library(  jnigraphics-lib
        jnigraphics )

target_link_libraries(
                       native-lib
                        ${jnigraphics-lib}
                       ${log-lib} )
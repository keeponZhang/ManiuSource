
cmake_minimum_required(VERSION 3.4.1)
add_library(
             native-lib
             SHARED
             native-lib.cpp )
message("---------------")
message(${ANDROID_ABI})
message(${ANDROID_NDK})
message(${ANDROID_PLATFORM})
message(${ANDROID_TOOLCHAIN})
find_library(
              log-lib
              log )
target_link_libraries(
                       native-lib
                       ${log-lib} )
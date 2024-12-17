# Project/lib/CMakeLists.txt

# 定义一个库
add_library(mylib STATIC src/lib.cpp)

# 设置库的头文件
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
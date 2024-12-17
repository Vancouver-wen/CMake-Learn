cmake_minimum_required(VERSION 3.10)
project(CALC) # project 工程名
set(CMAKE_CXX_STANDARD 11) # 设置c++标准

set(headpath ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

# 生成静态库
add_library(
    static_app STATIC 
    ${SRC_LIST}
)
target_include_directories(static_app PUBLIC ${headpath})

# 生成动态库
add_library(
    shared_app SHARED
    ${SRC_LIST}
)
target_include_directories(shared_app PUBLIC ${headpath})

# 生成可执行文件
# include_directories(${headpath}) # 被抛弃
add_executable(app main.cpp ${SRC_LIST})
target_include_directories(app PUBLIC ${headpath})
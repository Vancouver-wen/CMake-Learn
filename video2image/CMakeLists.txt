cmake_minimum_required(VERSION 3.10)
project(VideoToImages)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(VideoToImages main.cpp)

# 查找 OpenCV 包
find_package(OpenCV REQUIRED)

# 为目标添加头文件搜索路径
target_include_directories(VideoToImages PRIVATE ${OpenCV_INCLUDE_DIRS})

# 链接 OpenCV 库
target_link_libraries(VideoToImages PRIVATE ${OpenCV_LIBS})
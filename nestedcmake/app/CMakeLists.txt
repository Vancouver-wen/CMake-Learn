# Project/app/CMakeLists.txt

# 定义一个可执行文件
add_executable(myapp src/main.cpp)

# 链接库到可执行文件
target_link_libraries(myapp PRIVATE mylib)

# 添加 include 目录
target_include_directories(myapp PRIVATE ${PROJECT_SOURCE_DIR}/lib/include)
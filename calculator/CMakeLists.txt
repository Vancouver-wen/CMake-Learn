cmake_minimum_required(VERSION 3.0)
project(CALC) # project 工程名

# add_executable(app main.cpp add.cpp div.cpp multi.cpp sub.cpp) # 可执行程序名 源文件名称

set(SRC_LIST main.cpp;add.cpp;div.cpp;multi.cpp;sub.cpp)
# set(SRC_LIST main.cpp add.cpp div.cpp multi.cpp sub.cpp) # 代码里使用 空格 进行分隔也完全可以
message(${SRC_LIST}) # 变量内部存储使用 ; 进行分隔  但显示时只进行简单的连接  实际上应该理解为 list（一个内部使用 ; 来分隔的list）
add_executable(app  ${SRC_LIST})
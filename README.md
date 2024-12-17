# CMake-Learn
学习CMake - 文字教程
https://www.bilibili.com/video/BV14s4y1g7Zj
https://subingwen.cn/cmake/CMake-primer/
https://subingwen.cn/cmake/CMake-advanced/
学习CMake - 视频教程
https://www.bilibili.com/video/BV1xa4y1R7vT

##### gcc g++的区别与联系：
```
都是编译器
前者用于编译 c语言，后者用于编译c++
```

##### toolchain：
1. 预处理器 : 头文件展开、替换宏、去掉注释
2. 编译（gcc或者g++）
3. 汇编器（得到二进制文件 win下是.obj  linux下是 .0）
4. 链接器（将多个二进制文件，变成一个二进制文件，也就是可执行程序）


##### 手动编译cpp文件

```shell
g++ *.cpp -o calculator
./calculator
```

##### 使用CMake编译
```shell
cmake CMakeLists.txt
make
./app
```
```shell
cmake -P cmk.cmake
make
./app
```
一种更加美观的方式（防止目录混乱）(所有的编译结果都放在build中)，与源代码隔离
```shell
mkdir build
cd build
cmake ..
make
./app
```
不使用make命令 -> 要求cmake版本至少 3.20
```shell
mkdir build
cmake -B build -S . # -B 表示构建目录：会生成一个build目录并在build目录下存储临时文件  -S 表示包含 CMakeLists.txt 文件的源代码目录
# 也可以直接使用 cmake -B build  # 因为 -S 选项默认当前目录
cmake --build build # 根据build目录 编译汇编链接成可执行二进制程序
```
使用conda来管理cmake版本
```shell
conda create -n cmake
conda install cmake # 默认安装最新版本的cmake
```

##### 一个最简单的CMakeLists.txt
```shell
cmake_minimum_required(VERSION 3.0)
project(CALC)
# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
# 创建可执行程序
add_executable(app main.cpp add.cpp div.cpp multi.cpp sub.cpp) # 可执行程序名 源文件名称
```

##### CMake搜索源文件.cpp
```cmake
# 语法
file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
# 举例
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# CMAKE_CURRENT_SOURCE_DIR 宏表示当前访问的 CMakeLists.txt 文件所在的路径。
```

###### C++的静态库、动态库与头文件的关系
C++的静态库与动态库本身并不包含头文件，但在编译源代码为库文件或者使用库文件的时候需要知道头文件。
头文件将C++的接口与实现分离，可以可以保护实现的隐私（编译为库文件后保护了源码），但依然可以选择把接口暴露出去。

##### CMake为项目/库指定头文件
```cmake
# 第一种(很麻烦，不利于维护)
# 直接在.cpp文件中 #include 库文件的相对路径

# 第二种(已经被抛弃，不推荐使用)
include_directories(库文件目录)
# set(headpath ${CMAKE_CURRENT_SOURCE_DIR}/include)
# include_directories(${headpath})

# 第三种(官方推荐)
target_include_directories(项目名/库名 PUBLIC 库文件目录)
# set(headpath ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories(app PUBLIC ${headpath})
```
include_directories 与 target_include_directories 的联系：
两者都用于指定头文件的搜索路径，以便编译器在编译时能够找到所需的头文件

include_directories 与 target_include_directories 的区别：
1. 作用范围
include_directories：它添加的头文件搜索路径是全局的
target_include_directories：它添加的头文件搜索路径是目标特定的
2. 传递性
include_directories：它的参数直接是目录路径，没有区分 PRIVATE、PUBLIC 或 INTERFACE
target_include_directories：它需要指定目标名称，并且可以指定路径是 PRIVATE、PUBLIC 还是 INTERFACE，这决定了头文件路径是如何传递给依赖该目标的其他目标的
3. 现代CMake推荐使用 target_include_directories

##### CMake生成可执行文件、静态库、动态库
```cmake
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
```

##### CMake导入第三方库文件


#### CMake语言的其他语法

##### list语法：
```cmake
list(APPEND <list>[<element>...])列表添加元素
list(REMOVEITEM <list><value>[value...])列表删除元素
list(LENGTH <list><output variable>)获取列表元素个数
list(FIND <list><value><out-var>)在列表中查找元素返回索引
list(INSERT <list> <index>[<element>...]) 在index位置插入
list(REVERSE <list>)反转list
list(SORT <list> [...]) 排序list
```

##### 循环语句：
```cmake
foreach(<loop _var> RANGE <max>)
<commands>
endforeach()

foreach(<loop_var> RANGE <min> <max> [<step>])
<commands>
endforeach()

foreach(<loop_variable> IN [LISTS <lists>] [lTEMS <items>])
<commands>
endforeach()

while(<condition>)<commands>
endwhile()

message("---")
set(Ll one two three four)
set(L2 1 2 3 4 5)
foreach(num IN ZIP LISTS L1 L2)
message("word = ${num 0},num= ${num 1}")
endforeach()
```

##### 控制语句：
```cmake
if(<condition>)
<commands>
elseif(<condition>)
<commands>
else() 
<commands>
endif()

break continue
```


##### 函数：
```cmake
function(<name> [<argument>...])
<commands>
endfunction()

cmake minimum required(VERSION 3.20.0)
function(MyFunc FirstArg) # 参数传递时发生了复制，不会影响原来的变量
    message("MyFunc Name: ${CMAKE CURRENT FUNCTION}")
    message("FirstArg ${FirstArg}")
    set(FirstArg "New value")
    message("FirstArg again: ${FirstArg}")
    message("ARGVO ${ARGVO}")
    message("ARGV1 ${ARGV1}")
    message("ARGV2 ${ARGV2}")
endfunction()
set(FirstArg "first value")
MyFunc(${FirstArg} "value")
message("FirstArg ${FirstArg}")
```

##### 宏：
```cmake
CMake中的宏
macro(<name> [<argument>...])
<commands>
endmacro()
注意:尽量不要写宏，只要会读就好

cmake minimum required(VERSION 3.20.0)
macro(Test myVar)
    set(myVar"new value")
    message("argument: ${myVar}")
endmacro()
set(myVar "Fist value")
message("myVar: ${myVar}")
Test("value")
message("myVar: ${myVar}")

在进行预处理的时候，会发生宏替换
set(myVar "Fist value")
message("myVar: ${myVar}")
set(myVar"new value")
message("argument: ${myVar}")
message("myVar: ${myVar}")
```
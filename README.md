# CMake-Learn
学习CMake
https://subingwen.cn/cmake/CMake-primer/

##### gcc g++的区别与联系：

都是编译器

前者用于编译 c语言，后者用于编译c++



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
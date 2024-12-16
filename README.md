# CMake-Learn
学习CMake

##### gcc g++的区别与联系：

都是编译器

前者用于编译 c语言，后者用于编译c++



##### toolchain：

1. 预处理器 : 头文件展开、替换宏、去掉注释
2. 编译（gcc或者g++）
3. 汇编器（得到二进制文件 win下是.obj  linux下是 .0）
4. 链接器（将多个二进制文件，变成一个二进制文件，也就是可执行程序）



##### 手动编译单个cpp文件

```shell
// 存在 program.cpp
g++ program.cpp -o program
g++ *.cpp -o app
// g++会自动寻找main函数
```


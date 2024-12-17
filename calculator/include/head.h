#ifndef CALC_H
#define CALC_H

int add(int a,int b);

int subtract(int a,int b);

int multiply(int a,int b);

double divide(int a,int b);

#endif

/*
#ifndef CALC_H、#define CALC_H 和 #endif 这样的宏定义
在 C 和 C++ 编程中用于实现头文件的包含保护，防止头文件被重复包含。
这是一种常见的做法，用来避免在
多个源文件中包含同一个头文件时出现的编译错误和潜在的无限递归包含问题。
*/
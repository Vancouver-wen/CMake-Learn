// Project/app/src/main.cpp

#include<iostream>
#include "mylib.h"

int main() {
    Lib lib;
    int result = lib.add(2, 3);
    std::cout<<result<<std::endl;
    return 0;
}
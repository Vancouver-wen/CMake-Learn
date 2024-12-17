#include<stdio.h>
#include<iostream>
#include "head.h"
#include <boost/format.hpp>

int main(){
    int a=20;
    int b=12;
    std::cout<<boost::format("a=%1% b=%2%") % a % b<< std::endl;
    std::cout<<boost::format("a+b=%1%")%add(a,b)<<std::endl;
    std::cout<<boost::format("a-b=%1%")%subtract(a,b)<<std::endl;
    std::cout<<boost::format("a*b=%1%")%multiply(a,b)<<std::endl;
    std::cout<<boost::format("a/b=%1%")%divide(a,b)<<std::endl;
}
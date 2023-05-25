#include <iostream>
#include "ArrayList.h"
#include "iostream"

using namespace std;

class Person {
public:
    int a = 10;
    int b = 10;
//    开小灶   开特例 灵活一些
    mutable int c = 100;
public:

    void showPerson() const {
//        目的是不让其他人修改内部的变量
//这里不能修改a
//        a = 100;
//可以修改mutable修饰的变量
        c = 100;
    }
};

int main() {
//    普通对象 常对象  不能改变的对象  单例  --》 配置信息--》Config  config 常对象
    const Person person;
    //常对象可以修改mutable修饰的变量
    person.c = 100;
    //不能修改a的变量
    //person.a = 500;

    //Person person2;
    //person2.a = 500;
    return 0;
}

#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
class Person{
public:
    int a = 10;
      int b = 10;
//    开小灶   开特例 灵活一些
    mutable int c = 100;
public:

     void  showPerson( ) const{
//        目的   不让其他人修改内部的变量
//        a = 100;
         c = 100;
    }
};
int main() {
//    普通对象 常 对象  不嫩改变的对象  单利  --》 配置信息--》Config  config 常对象
   const  Person person;
   person.c = 100;
   return 0;
}

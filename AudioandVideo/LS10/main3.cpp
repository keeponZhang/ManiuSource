#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
class Person{
private:
//    最大元素的整数倍
    int a = 10;
    char b = 'b';
    static int e  ;
//    9 个字节  16 个字节
//    8  1   5个字节 2
public:
    void test(){

    }
};

struct Person1{
//     8  1   1个字节 2
    double a = 10;
    char b = 'b';

};
int main() {
    Person   person;
//    8 1   其他字节
    cout << "size =  " << sizeof(person) << endl;
    Person1 person1;
    cout << "size =  " << sizeof(person1) << endl;
    return 0;
}

#include <iostream>
using namespace std;

class Person1{
    Person1(int a){

    }

    Person1(const int &a){

    }
};
void test(int a){
    cout << "test a:  " << a << endl;
    a = 200;
}
//int *p
//*p引用  理解  引用
void test1( int& a){
    cout << "test1 a:  " << a << endl;
    a = 200;
}
void test2(const int& a){
    cout << "test1 a:  " << a << endl;
    //不能改变
    //a = 200;
}
int main() {

    int a = 10;
    cout << "before a:  " << a << endl;
    test(a);
    cout << "after a:  " << a << endl;
    test1(a);
    cout << "after a:  " << a << endl;
//    Person1 p1=Person1(20);//不能重载   函数指针
}
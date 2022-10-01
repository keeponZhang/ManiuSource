#include <iostream>
using namespace std;

class Person1{
    Person1(int a){

    }

    Person1(const int &a){

    }
};
void test(int a){
    cout << "a:  " << a << endl;
    a = 200;
}
//int *p
//*p引用  理解  引用
 test1(const int& a){
    cout << "a:  " << a << endl;
//    a = 200;
}
int main() {

    int a = 10;
    cout << "befor a:  " << a << endl;
    test(a);
    cout << "after a:  " << a << endl;
    test1(a);
    cout << "after a:  " << a << endl;
//    Person1 p1=Person1(20);//不能重载   函数指针
}
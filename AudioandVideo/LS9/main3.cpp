#include <iostream>
using namespace std;

class Person{
public:
    int age;
public:
////    构造参数声明
    Person(){
        cout << "new person " << endl;
        }
    Person(int a) {
        cout << "new person int a, int b" << endl;
        this->age = a;
    }
//    析构函数  onDestyroy 没有重载
    ~Person(){
//        必须是无参
        cout << "delete  person " <<this->age<< endl;
    }
//    Person(const  Person &person) {
//        cout << "new person const &" << endl;
//    }
};
//拷贝函数调用 三种

//形参传递
//实例化对象  作为参数调用构造方法

//返回参数的时候
int main() {
    Person p3 = Person(10); //p3 先先销毁 1   p4先销毁
    Person p4 = Person(p3);//调用的拷贝函数 默认
    p4.age = 100;//p4先销毁     p3再销毁  栈先进后出
}
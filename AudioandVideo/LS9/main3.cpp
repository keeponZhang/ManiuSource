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
    Person(int age) {
        cout << "new person int age" << endl;
        this->age = age;
    }
//    析构函数  onDestyroy 没有重载
    ~Person(){
//        必须是无参
        cout << "delete  person " <<this->age<< endl;
    }
    Person(const  Person &person) {
        cout << "拷贝函数new person const &person=" <<person.age<< endl;
        age = person.age;
    }
};
Person test012() {
    printf("---------test02---------------\n");
    Person person1(1000);
    return person1;
}

//拷贝函数调用 三种
//形参传递
//实例化对象  作为参数调用构造方法
//返回参数的时候(好像不会)
int main() {
    //p4先销毁 ,p3再销毁  栈先进后出
    Person p3 = Person(10);
    //调用的拷贝函数 默认
    Person p4 = Person(p3);

    p4.age = 100;
    test012();
}
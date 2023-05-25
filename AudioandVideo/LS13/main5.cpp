#include <iostream>

using namespace std;
//泛型 这个说法  函数模板=泛型

//类上 使用
class Person1 {
public:
    void showPerson1() {
        cout << "Person1  showPerson1" << endl;
    }
};

class Person2 {
public:
    void showPerson2() {
        cout << "Person2  showPerson2" << endl;
    }
};

template<class T>
class MyClass {
//    C++extends   关键字   泛型 继承 T extends R  编译器不检查     泛型确认  运行时
//
public:
    T obj;
public:
    void func1() {
        obj.showPerson1();
    }

    void func2() {
        obj.showPerson2();
    }
};

int main() {
//    显示调度
    MyClass<Person1> p1;
    MyClass<Person2> p2;
    p1.func1();
    //加了这个编译不通过（泛型确认放在了运行时）
    //p1.func2();

    //p2.func1();
    p2.func2();



    return 0;
}

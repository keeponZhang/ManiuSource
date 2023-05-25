#include <iostream>
using namespace std;
//泛型 这个说法  函数模板=泛型

//类上 使用
template<typename T, typename R>
class Person {
public:
    Person(T name, R age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "a:" << this->m_Name << " age: " << this->m_Age << endl;
    }

    T m_Name;
    R m_Age;
};
int main() {
    //这样是错误
    //Person  p("david", 18);
    int age  = 22;
    //这样也是错误
    //Person  p2("david", age);
//    显示调度
    Person<string,int> p3("david", 18);
    p3.showPerson();

    return 0;
}

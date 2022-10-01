#include <iostream>
using namespace std;
class Child{
    int a;


};
class Person{
public:
    int a = 0;
    int b = 10;
    Child child;
////    构造参数声明
        Person(){
        cout << "new person " << endl;

        }
      Person(int a){
          this->a = a;
         cout << "new person int a" << endl;
    }
    Person(int a, int b) {
        cout << "new person int a, int b" << endl;
    }


    //拷贝函数   常量指针   指向常量的指针   常量引用    person
    Person(const  Person &person) {
        cout << "new person const &" << endl;
//        cout << "new person const  Person &person" << endl;
//类似于   C++补全这些代码
        a = person.a;
        b = person.b;
//        person.a = 10;
//        常量引用 只能够读 不能存
    }
////    拷贝
//     Person(Person  &person){
//        cout << "new person &" << endl;
//       a = person.a;
//        person.a = 100;
//    }

//    }
//    析构函数  onDestyroy 没有重载
    ~Person(){
//        必须是无参
        cout << "delete person" << endl;
    }
};

void test02(Person person){
//    音视频  拷贝函数   -----》 成员copy  找不到
    cout << "  person a: " <<person.a<< endl;
}
int main() {
//    实例化一次对象 1   实例化两次 2
    Person person1 = Person(10);//隐士法 实例化了一个对象
    test02(person1);

//    cout << "person a   " <<person1.a<< endl;
//    作为参数传递  因为需要test02方法内存需要  实例化Person  所以  拷贝函数
//
//    Person person(person1);
    return 0;
//显示法  Person person=Person()
//括号法  Person person()
// 隐士法  Person person=10
}
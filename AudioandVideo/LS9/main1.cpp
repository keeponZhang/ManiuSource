#include <iostream>

using namespace std;

class Child {
    int a;


};

class Person {
public:
    int a = 0;
    int b = 10;
    Child child;

////    构造参数声明
    Person() {
        cout << "new person " << endl;

    }

    Person(int a) {
        this->a = a;
        cout << "new person int a" << endl;
    }

    Person(int a, int b) {
        cout << "new person int a, int b" << endl;
    }


    //拷贝函数
    //常量指针是指向常量的指针； 常量引用等于常量指针
    Person(const Person &person) {
        cout << "拷贝函数 new person  const &person： " << endl;
//类似于   C++补全这些代码
        a = person.a;
        b = person.b;
// 常量引用 只能够读 不能存
    }

// 拷贝函数,比上面那个带const的优先级高，都有回调用这个
    Person(Person &person) {
        cout << "拷贝函数 new person  &person：" << endl;
        //a = person.a;
        person.a = 200;
        a = 100;
    }

//    }
//    析构函数  onDestyroy 没有重载
    ~Person() {
//        必须是无参
        cout << "delete person" << endl;
    }
};

//形参从实参拷贝
void test02(Person person) {
    printf("---------test02---------------\n");
//    音视频  拷贝函数   -----》 成员copy  找不到
    cout << "test02  person a: " <<person.a<< endl;
}

int main() {
//    实例化一次对象1次（另外会调用一次拷贝构造函数），析构2次
    Person person1 = Person(10);//隐士法 实例化了一个对象
    test02(person1);
    cout << "person a   " <<person1.a<< endl;
    //printf("-----------------------\n");
    //Person person2 =11;//隐式法 实例化了一个对象
    //test02(person2);


//    作为参数传递  因为需要test02方法内存需要  实例化Person  所以  拷贝函数
//    Person person(person1);
    return 0;

}
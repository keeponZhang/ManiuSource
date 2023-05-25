#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "new person " << endl;
    }

////    构造参数声明
    Person(int a) {
        cout << "new person int a" << endl;
    }
    Person(double a) {
        cout << "new person double a" << endl;
    }

   explicit Person(char *a) {
        cout << "new double person char *a" << endl;
    }

    Person(int a, int b) {
        cout << "new person int a, int b" << endl;
    }

//    析构函数  onDestroy 没有重载
    ~Person() {
//        必须是无参
        cout << "delete person" << endl;
    }
};



int testOriginal() {
    return 0;
//显示法  Person person=Person()
//括号法  Person person()
// 隐式法  Person person=10
}


void testMain2() {
    printf("---------testMain2---------------\n");
    //    java Person person=new Person()
//实例化对象 也是声明  已经开辟内存 堆区 1  栈区 2  new malloc
//最简单的声明
//括号实例化对象
    Person person;
    Person person2 = Person();
    Person person3(10) ;
    Person person4(10,20) ;

}

void testMain3() {
    printf("---------testMain3---------------\n");
    //   显示法  new  堆区       栈区声明
    Person p2 = Person();
    Person p3 = Person(10);
    Person p4 = Person(10, 220);
}

void testMain4() {
    printf("---------testMain4---------------\n");
    //   隐式法是在栈区，  new，malloc是在堆区
    int a = 10;
    double b = 20.0;
// 只能调用一个参数的构造函数
    Person p3 = a;
    Person p4 = b ;
    //加了explicit关键字不能隐式调用
    //Person p5 = "c" ;
}

void testMain5() {
    printf("---------testMain5---------------\n");
    // 实例化了4 个 person
    Person person[4];

    Person person1 =11;
    system("pause");
    printf("---------testMain5 end---------------\n");
}

void testMain6() {
    printf("---------testMain6---------------\n");
}

void testMain7() {
    printf("---------testMain7---------------\n");
}

int main() {
    //testMain2();
    //testMain3();
    testMain4();
    testMain5();
    //testMain6();
    //testMain7();
    return 0;
}

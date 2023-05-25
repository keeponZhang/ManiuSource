#include <iostream>
#include "string.h"

using namespace std;

//C++更细化了  访问方式
class Parent {
public:
    void printP() {
        cout << "Parent printP() " << endl;
    }

    //这个虚函数很重要
    void printC() {
        cout << "Parent printC() " << endl;
    }

    virtual void printD() {
        cout << "Parent printD() " << endl;
    }

    Parent() {
        cout << "构造函数Parent Parent()" << endl;
    }

    //父类的拷贝构造函数
    Parent(const Parent &obj) {
        cout << "拷贝函数Parent const Parent()" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "构造函数Child Child()" << endl;
    }

    void printC() {
        cout << "Child 重写 printC()" << endl;
    }

    void printD() {
        cout << "Child 重写 printD()" << endl;
    }
};

//通过指针传递        那么只会调用父类型的方法
void howToPrint(Parent *p) {
    printf("------------howToPrint-------------\n");
    p->printP();
    p->printC();
    p->printD();
}
//如果是引用类型，父类方法用virtual修饰，并且子类重写，会调用到子类重写的那个方法
void howToPrint1(Parent &p) {
    printf("------------howToPrint1-------------\n");
    p.printP();
    p.printC();
    p.printD();

}

int main22() {



////    引用类型作为参数   java  子类的方法重写   调用重写

//子类  方法
    return 0;
}

void testMain2() {
    printf("---------testMain2---------------\n");
    Parent p1;
    p1.printC();
    //Parent
//    输出
//    Parent Parent()
//    Parent printC()
}

void testMain3() {
    printf("---------testMain3---------------\n");
    Child c1;
    c1.printC();
    c1.printP();

    //    输出
    //构造函数Parent Parent()
    //构造函数Child Child()
    //Child printC()
    //Parent printP()

}

void testMain4() {
    printf("---------testMain4---------------\n");
    Child c1;
    //这里会调用拷贝函数
    Parent pa = c1;
    //这里调用的还是父类的
    pa.printC();
    pa.printD();
    pa.printP();

    //    输出
    //构造函数Parent Parent()
    //构造函数Child Child()
    //拷贝函数Parent const Parent()
    //Parent printC()
    //Parent printP()
}

void testMain5() {
    printf("---------testMain5---------------\n");
    Parent *p = NULL;
    Child c1;
    p = &c1;
    //这里调用的是子类的
    p->printC();
    p->printD();
    p->printP();
    //    输出  只有父类方法被virtual修饰，才能调用到子类覆写的方法
    //构造函数Parent Parent()
    //构造函数Child Child()
    //Parent printC()
    //Child 重写 printD()
    //Parent printP()
}

void testMain6() {
    printf("---------testMain6---------------\n");
    Parent p1;
    howToPrint(&p1);
    howToPrint1(p1);
    printf("-------------------------\n");
    Child c1;
    //Parent *p = NULL;
    //p = &c1;

    howToPrint1(c1);
}

void testMain7() {
    printf("---------testMain7---------------\n");


}

int main() {
    testMain2();
    testMain3();
    testMain4();
    testMain5();
    testMain6();
    //testMain7();
    return 0;
}
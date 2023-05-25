#include <iostream>
#include "string.h"

using namespace std;

class PureEmpty {

};

class ParentNoVirtual {
public:
    //纯虚函数，返回0，必须让要子类实现的
    void speak() {
        cout << "ParentNoVirtual::speak1" << endl;
    };

    void speak1() {
        cout << "ParentPureVirtual::speak1" << endl;
    }
};

class ParentNoVirtualWithPointer {
public:
    int *ptv;

    //纯虚函数，返回0，必须让要子类实现的
    void speak() {
        cout << "ParentNoVirtual::speak1" << endl;
    };

    void speak1() {
        cout << "ParentPureVirtual::speak1" << endl;
    }
};

//C++更细化了  访问方式 Parent1   1个字节   不会因为你增加了 普通函数  而增加内容
class ParentPureVirtual {
public:
    //纯虚函数，返回0，必须让要子类实现的
    virtual void speak() = 0;

    void speak1() {
        cout << "ParentPureVirtual::speak1" << endl;
    }
};

class ParentVirtual {
public:
    //纯虚函数，返回0，必须让要子类实现的
    virtual void speak() {
        cout << "ParentVirtual::virtual speak" << endl;
    };

    void speak1() {
        cout << "ParentVirtual::speak1" << endl;
    }
};

//延申java   多态    函数表  C++  8  =指向一个虚寒函数数组的 指针 int *
class Parent2 {
private:
    int a;
protected:
    int b;
//    纯虚函数     virtual void  speak()=0  必须要让子类实现   虚函数virtual void  speak(){}
//    virtual void f() { cout << "Parent::f" << endl; }
//    virtual void g() { cout << "Parent::g" << endl; }
//    virtual void h() { cout << "Parent::h" << endl; }
};


class ChildExtendsPureVirtual : public ParentPureVirtual {
public:
    void speak() {
        cout << "ChildExtendsPureVirtual::speak" << endl;
    }

    void speak1() {
        cout << "ChildExtendsPureVirtual::speak1" << endl;
    }
};

class ChildExtendsVirtual : public ParentVirtual {
public:
    void speak() {
        cout << "ChildExtendsVirtual::speak" << endl;
    }

    void speak1() {
        cout << "ChildExtendsVirtual::speak1" << endl;
    }
};

class ChildExtendsParent2 : public Parent2 {

};

void testMain2() {
    printf("---------testMain2---------------\n");
    //这里会报错，纯虚函数式不能实例化的，相当于java的abstract
    //ParentPureVirtual parentPureVirtual;
    //parentPureVirtual.speak();

    ParentVirtual parentVirtual;
    parentVirtual.speak();
}

void testMain3() {
    printf("---------testMain3---------------\n");
    ChildExtendsPureVirtual childExtendsPureVirtual;
    childExtendsPureVirtual.speak();

    ChildExtendsVirtual childExtendsVirtual;
    childExtendsVirtual.speak();

}

void testMain4() {
    printf("---------testMain4---------------\n");
    ChildExtendsVirtual childExtendsVirtual = ChildExtendsVirtual();
    ParentVirtual parentVirtual = childExtendsVirtual;
    parentVirtual.speak();
}

void testMain5() {
    printf("---------testMain5---------------\n");
    //很奇怪，这样才能调用到子类实现的speak方法
    ChildExtendsVirtual *childExtendsVirtual = new ChildExtendsVirtual();
    ParentVirtual *parentVirtual = childExtendsVirtual;
    parentVirtual->speak();
}

void testMain6() {
    printf("---------testMain6---------------\n");
    cout << "PureEmpty.size " << sizeof(PureEmpty) << endl;

    cout << "ParentNoVirtual.size " << sizeof(ParentNoVirtual) << endl;
    cout << "ParentNoVirtualWithPointer.size " << sizeof(ParentNoVirtualWithPointer) << endl;
    //虚函数会占用字节
    cout << "ParentPureVirtual.size " << sizeof(ParentPureVirtual) << endl;

    //8个字节
    cout << "ChildExtendsParent2.size " << sizeof(ChildExtendsParent2) << endl;

}
class Parent3 {
    virtual void f() { cout << "Parent3::f" << endl; }

    virtual void g() { cout << "Parent3::g" << endl; }

    virtual void h() { cout << "Parent3::h" << endl; }
};

void testMain7() {
    printf("---------testMain7---------------\n");
    Parent3 b;
    typedef void (*func)(void);
    func func1 = NULL;
    //虚函数首地址
    cout << "adress:   " << (int *) (&b) << endl;
    //找到了虚函数表的元素（虚函数表的第一个元素）
    cout << "*adress:   " << *(int *) (&b) << endl;
    //虚函数表的第一个元素是一个函数指针
    cout << " method adress:  " << (int *) *(int *) (&b) << endl;
    func1 = (func) *((int *) *(int *) (&b));
    func1();
}

int main() {
    testMain2();
    testMain3();
    testMain4();
    testMain5();
    testMain6();
    testMain7();
    return 0;
}
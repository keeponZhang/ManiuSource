#include <iostream>

using namespace std;

#include "include/Maniu.h"

//  调用出错 ----》不算重载
//函数指针----》避免 二义性
//void test(int  a){//int 和int &冲突的
//    cout << "int a: " << a << endl;
//}

//test2 编译不通过

//重载
//test（10） 二义性
void test2(int a) {
    cout << "int a: " << a << endl;
}

void test2(int &a) {//int 和int &冲突的，这2个不算重载函数
    cout << "int&  a: " << a << endl;
}

void testMain2() {
    printf("---------testMain2---------------\n");
    int a = 10;
    int &b = a;
    //这里报错
    //test2(a);
}


//int 和int &冲突的
void test(int &a) {
    cout << "int&  a: " << a << endl;
}
////int 和int &冲突的
//void test(int a) {
//    cout << "int&  a: " << a << endl;
//}

void test(int *a) {
    cout << "int*  a: " << a << endl;
}

//常量引用可以理解为常量
void test(const int &a) {
    cout << "const int& a: " << a << endl;
}

/**
 *
 *
 * 算重载  常量指针  指向常量的指针
 * 是指指向常量的指针，顾名思义，就是指针指向的是常量，
 */
void test(const int *a) {
    cout << "const  int a: " << a << endl;
}
//引用
//不算重载  指针常量  指向的是变量，会造成二义性问题
//void test(int * const   a){
//    cout << "const  int a: " << a << endl;
//}

void test(char *a) {
    printf("c: %c,", *a);
}

void test(const char *a) {
    printf("const c: %c", *a);
}

void testMain3() {
    printf("---------testMain3---------------\n");
    //    调用的哪个类型 不允许出现二义性

    int a = 10;
    int &b = a;
    //这里报错
    test(a);
    test(&a);
    int const c = 10;
    cout << "const &c: " << &c << endl;
    int const *d = &c;
    test(d);
    test("f");
}


void test4(int a, int b = 10) {
    cout << "test4 int a: " << a << "  int b: " << b << endl;
}

void test4(int a) {
    cout << "test4 int a: " << a << endl;
}

void test4(char *a) {
    cout << "test4 *a: " << *a << endl;
}

void test4(int &a) {
    cout << "test4 int& a  : " << a << endl;
}

//相当于取了一个别名
typedef void (myFuncTest)(int a, int b);

typedef void (myFuncTest2)(int a);

typedef void (myFuncTest22)(int &a);

typedef void (*myFuncTest3)(int a);

typedef void (*myFuncTest4)(char *);

typedef void (*myFuncTest5)(int &a);

//只是定义了一个变量
void (*myFunc2)(int a, int b);

void testMain4() {
    printf("---------testMain4---------------\n");
    //函数指针
    myFuncTest *func = test4;

    //只传一个参数是不行的
    //func(10);
    func(10, 20);

    //通过函数指针可以正确调用
    myFuncTest2 *func2 = test4;
    func2(50);
    //通过函数指针可以正确调用
    myFuncTest22 *func22 = test4;
    int k = 51;
    func22(k);

    myFuncTest3 func3 = test4;
    func3(60);


    myFunc2 = test4;
    myFunc2(100, 200);

    myFuncTest4 func5 = test4;
    char d = 'd';
    func5(&d);

    int f = 7;
    myFuncTest5 func6 = test4;
    func6(f);
}

void testMain5() {
    printf("---------testMain5---------------\n");
    //实例化在堆区，变量
    Maniu *maniu = new Maniu;
    maniu->setAge(18);
    maniu->getAge();
    maniu->age;
    cout << "age int a: " << maniu->getAge() << endl;
}

void testMain6() {
    printf("---------testMain6---------------\n");
}

void testMain7() {
    printf("---------testMain7---------------\n");
}






//int main8() {
////    堆区1  栈区  2 maniu栈区

////    func3("C");
//}

int main() {
    //testMain2();
    //testMain3();
    //testMain4();
    testMain5();
    //testMain6();
    //testMain7();
    return 0;
}
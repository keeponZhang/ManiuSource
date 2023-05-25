#include <iostream>

using namespace std;

//泛型 这个说法  函数模板=泛型
class Person {
public:
    int a;
    int b;
};

template<class T>
T myAdd(T a, T b) {
    cout << "泛型函数====myAdd(T a,T b)======" << endl;
    return a + b;
};

template<class T>
T myAdd(T a, T b, T c) {
    cout << "泛型函数====myAdd(T a,T b, T c)======" << endl;
    return a + b + c;
}

int myAdd(int a, int b) {
    cout << "普通函数===myAdd(int a,int b)=======" << a << " b=" << b << endl;
    return a + b;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a = 10;
    int b = 20;
    char c = 'a';


    //1 当有普通函数 和泛型函数重合时  优先调用普通函数
    myAdd(3, 4);
    myAdd<>(1, 2);
//    2 如果你指明 是调用泛型函数    泛型
//普通函数 与  泛型函数不冲突  先泛型函数
    myAdd('c', 'b');
    myAdd(1, 2, 1);
//    显示调度
    return 0;
}

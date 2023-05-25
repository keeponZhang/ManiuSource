#include <iostream>

void mySwapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void mySwapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

template<typename T>
void mySwap2() {
    T t;//声明  类型  分配不了内存
}

//方法泛型，只会对当前的方法起作用
template<typename T>
//typename  可以替换成 class
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//void mySwap3(T &a, T &b){
//    T temp = a;
//    a = b;
//    b = temp;
//}
int main() {

    int a = 10;
    int b = 20;
    char c = 'a';
    int d = 1;
    int f = 2;
    std::cout << "before a=" << a << " b=" << b << std::endl;
//    显示调度，泛型要传一样类型
    mySwap<int>(a, b);
    std::cout << "after a=" << a << " b=" << b << std::endl;
    //    隐式调度
    mySwap(d, f);
    std::cout << "after d=" << d << " f=" << f << std::endl;

    //这个会报错，推导不出来
    //mySwap(d, c);
    std::cout << "after d=" << d << " c=" << c << std::endl;
    //这个会报错，推导不出来
    //mySwap2();
    return 0;
}

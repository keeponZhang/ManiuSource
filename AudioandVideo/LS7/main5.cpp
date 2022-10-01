#include <iostream>

using namespace std;
float temp;

float fn1(float r) {
    float temp = (float) (r * r * 3.14);
    return temp;

}
//常量引用    const  &
float & fn2(float r) {
    //函数结束后，fn2就不见了
    float fn2 = (float) (r * r * 3.14);
//    float &b = temp;
    return fn2;
}

//float a = fn1(10);  float &c = fn1(10)
float &fn3(float r) {//定义函数fn2，它以引用方式返回函数值
     temp = (float) (r * r * 3.14);
//    float &b = temp;
    return temp;
}

//如果函数返回是&，内部可以直接return(float)(r*r*3.14)吗？
int main() {
    float a = fn1(10.0);
    cout << "a=" << a<< endl;
    //这个会崩溃，函数结束后，fn2就不见了
   // float b = fn2(100.0);
   //cout << " b=" << b<< endl;

    float c = fn3(100.0);
    cout << "c=" << c<< endl;

    //printf("---------main---------------\n");
    //float cc = 1;
    //float &d1 = cc;
    //这个不行，
    //float &d = fn1(10.0);
    float &e = fn3(50.0);
    cout << "e=" << e<< endl;
}

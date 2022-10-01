#include <iostream>
#include "include/Maniu.h"
using namespace std;
#define ADD(x,y) (x+y)
// 重载 结合 起来
//默认参数  free  malloc  new   free()  析构函数 C++内存该如何诗函
void test(int x, int y = 10,int =10) {


}
//实参一定写在前面   默认参数一定写在后面
void test2(int a, int b, int c = 10, int d = 20) {
    cout << "a: " << a<<" b: " << b<<" c: " << c<<" d: " << d  << endl;
}
//int= 0  没有变量名  用不到
void test3(int a, int b, int= 0){
    a = 20;
    b=3;

}


//void test(int x, int y) {
//
//
//}
int main() {
    test(10);
    test(10, 20);
    test2(1,2);
    test2(1, 2, 3);
    test3(10, 20, 30);
    return 0;
}

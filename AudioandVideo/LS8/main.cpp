#include <iostream>
using namespace std;
#define ADD(x,y) (x+y)
//inline 内联函数    define

//Log   Text.isEmpty()
//复杂  inline  消除掉    作为普通函数的一种  调用了
  inline  int Add(int x,int y){
//    for (int i = 0; i < ; ++i) {
//
//    }
//    switch () {
//
//    }
//    Add()
//    内联
   return x + y;
}


int main() {
//    频率非常
    std::cout << "Hello, World!" << std::endl;
//    int ret1 = Add(10,20);//30*10  10+20*10
//    cout << "ret1:" << ret1 << endl;
    return 0;
}

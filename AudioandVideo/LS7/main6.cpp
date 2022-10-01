#include <iostream>
using namespace std;
int vals[10];
int error = -1;
//*   =  &
 int &put(int n){

    if (n >= 0 && n <= 9) {
        int &d = vals[n];
//        return d;//int
        return  vals[n];
    } else {
        cout << "subscript error";
        return error;
    }

}
int main(){
    put(0) = 10;// 第零个元素   引用  =10  以put(0)函数值作为左值，等价于vals[0]=10
//    d=10
    put(9) = 20;//以put(9)函数值作为左值，等价于vals[9]=20;
    cout << vals[0] << endl;//10
    cout << vals[9] << endl;//20
}

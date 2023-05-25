#include <iostream>

using namespace std;
//泛型 这个说法  函数模板=泛型

//类上 使用
template<typename T>
class A {
public:
    T t;
public:
    A(T t) {
        this->t = t;
    }

//  变量引用
    T &getT() {
        //这里返回全局的，不然方法执行完会被释放掉
        return t;
    }

};

int main() {

    A<int> a(100);
    cout << "a.getT():" << a.getT() << " " << endl;
    return 0;
}

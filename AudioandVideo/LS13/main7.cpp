#include <iostream>
using namespace std;
//泛型 这个说法  函数模板=泛型
template <class T>
class Base
{
public:
    T m_A;
};
//template <class T>  父类有泛型  在子类中一定要制定  方法上  T
class Son: public Base<int>{
};

//FFmpeg  泛型    引用
template<class T>
class Base2
{
public:
    T m_A;
};
template<class T1 ,class T2>
class Son2: public Base2<T2>{
public:
    Son2()
    {
    }
private:
    T1 m_B;
};

//字符串
int main() {
    return 0;
}

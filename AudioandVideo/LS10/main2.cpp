#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
class Instance{
public:
    static Instance *getInstance(){
        //需要在类外初始化
        //if (instance == nullptr) {
        //    instance = new Instance;
        //}
        return instance;
    }
//
private:
    static Instance *instance  ;
private:
    //保护构造方法
    Instance(){};
    Instance(const Instance &){};

};
//单例的初始化
Instance *  Instance::instance = new Instance;
int main() {
    //这几个方式都不能实例化构造
    //Instance instance;
    //Instance c2;
    //Instance * c3 = new Instance;
    //Instance * c1 = Instance::instance;

    Instance * c1 = Instance::getInstance();
    Instance * c2 = Instance::getInstance();
    if (c1 == c2)
    {
        cout << "c1 = c2" << endl;
    }
    else
    {
        cout << "c1 != c2" << endl;
    }
//构造拷贝函数
    Instance *c3 =  Instance::getInstance();

    if (c1 == c3)
    {
        cout << "c1 = c3" << endl;
    }
    else
    {
        cout << "c1 != c3" << endl;
    }

    //如果拷贝函数没有私有化，下面的表达式是不会报错的，现在因为私有化了拷贝构造函数，所以会报错
    //Instance *c4 = new Instance(*c3);
    return 0;
}

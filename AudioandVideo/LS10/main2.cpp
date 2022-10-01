#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
class Instance{
public:
    static Instance *getInstance(){
//        if (instance == nullptr) {
//            instance = new Instance;
//        }
        return instance;
    }
//
private:
    static Instance *instance  ;
private:
    Instance(){};
    Instance(const Instance &){};

};
Instance *  Instance::instance = new Instance;
int main() {
//    Instance instance;
//    Instance c2;
//    Instance * c3 = new Instance;
//    Instance * c1 = Instance::instance;

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
    return 0;
}

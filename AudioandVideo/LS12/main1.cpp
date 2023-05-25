#include <iostream>
#include "string.h"
using namespace std;
//C++更细化了  访问方式
class Parent {
public:
    int name;// 名字
protected:
    char * str;
//    构造函数与析构函数调用
public:
    Parent(char * str)
    {
        if (str != NULL)
        {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        }
        else {
            this->str = NULL;
        }
        cout << "构造函数 parent () " << str << endl;
    }
    ~Parent(){
        cout << "析构函数 delete parent () " << str << endl;
    }
};
//析构调用


//: extends   C++多级
class Child: public Parent{
public:
//    如何父类构造方法
    Child(char *str) : Parent(str) {
        if (str != NULL) {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        } else {
            this->str = NULL;
        }
        cout << "构造函数 Child () " << str << endl;
    }
    ~Child(){
        cout << "析构函数 delete Child () " << str << endl;
    }
};

int main() {
//    类外访问
    std::cout << "Hello, World!" << std::endl;
    //delete parent 会调用2次
    Parent parent = Child("david");
    return 0;
}

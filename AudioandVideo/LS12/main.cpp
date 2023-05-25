#include <iostream>

//C++更细化了  访问方式
class Parent {
public:
    int name;// 名字
protected:
    int bank;//银行账户
private:
    int xifu;//媳妇

};

class Parent1 {
public:
    int age;// 名字

};


//: extends   C++可以多继承 (public公有继承)
class ChildExtendPublic  : public Parent, Parent1 {

    void test() {
        this->age;
        this->name;
        this->bank;
        //不能够访问私有属性
//        this.xifu
    }
};
class ChildExtendsProtect : protected Parent {

    void test() {
        this->name;
        this->bank;
//        this->xifu
//不能够访问私有属性
    }
};

//派生的方式  private
class ChildExtendPrivate : private Parent {

    void test() {
        this->name;
        this->bank;
        //不能够访问私有属性
        //this->xifu;
    }
};


//默认私有集成   class ChildExtendDefault:  private  Parent
class ChildExtendDefault : Parent {
    void test() {
        this->name;
        this->bank;
        //不能够访问私有属性
        //this->xifu ;
    }

};

int main() {
//    类外访问
    std::cout << "Hello, World!" << std::endl;
    ChildExtendPublic extendPublic;
//    public
    extendPublic.name;
    //extendPublic.bank;
    //extendPublic.xifu;

    ChildExtendsProtect extendsProtect;
    //extendsProtect.name;
    //extendsProtect.bank;
    //extendsProtect.xifu;



    ChildExtendPrivate extendPrivate;
    //extendPrivate.name;
    //extendPrivate.bank;
    //extendPrivate.xifu;


    ChildExtendDefault childExtendDefault;
    //childExtendDefault.name;
    //childExtendDefault.bank;
    //childExtendDefault.xifu;
    return 0;
}

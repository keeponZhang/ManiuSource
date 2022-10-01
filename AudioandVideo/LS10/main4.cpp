#include <iostream>
#include "string"

using namespace std;

class Xifu;
class LaoWang {
public:
    LaoWang();
    void visit();

private:
    Xifu *xifu;
};

class Xifu {
    //让好基友类 作为Building的好朋友  friend  暴露  自己的私有变量  私有方法

    friend class LaoWang;

public:
    Xifu();

public:
    int age =18;
private:
    string name;//姓名
};

LaoWang::LaoWang() {
    xifu = new Xifu;
}

void LaoWang::visit() {
    cout << "age:" << this->xifu->age << endl;
    cout << "name:" << this->xifu->name << endl;
}


Xifu::Xifu() {
    this->age = 18;
    this->name = "wangcai";
}

void test01() {
    LaoWang gg;
    gg.visit();
}


int main() {
    test01();
    return 0;
}
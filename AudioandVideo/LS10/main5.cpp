#include <iostream>
#include "string"

using namespace std;
class Xifu;
class LaoWang
{
public:
    LaoWang();

    void visit();

    void visit2();
private:
    Xifu *xifu;
};

class Xifu
{
//    友元函数
    friend  void LaoWang::visit() ;
public:
    Xifu();
public:
    int age =18;
private:
    string name;//姓名

};
//C++灵活
LaoWang::LaoWang()
{
    xifu = new Xifu;
}
void laowang(){
//    全局函数

}
void LaoWang::visit()
{
    cout << "age:" << this->xifu->age << endl;
    cout << "name:" << this->xifu->name << endl;
}

void LaoWang::visit2(){
    cout << "age:" << this->xifu->age << endl;
//    cout << "name:" << this->xifu->name << endl;  //不行的

}



Xifu::Xifu()
{
    this->age = 18;
    this->name = "xifu";
}
int main() {
    LaoWang laoWang;
    laoWang.visit();
    laoWang.visit2();
    return 0;
}
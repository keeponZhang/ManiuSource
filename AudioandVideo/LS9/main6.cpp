#include <iostream>
#include <string.h>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person" << endl;
    }
    Person(int a)
    {
        cout << "Person  int " << endl;
    }
    ~Person()
    {
        cout << "delete Person" << endl;
    }
};
void test01(){
//    堆区开辟内存 ==malloc （size）  void 强转    指针
//new   不需要传递对象的大小   返回声明的类型 ，同样是一个指针指针
    Person *person = new Person;
    //所有new出来的对象，都会返回该类型的指针
    //malloc返回void*还要强转
    //malloc会调用构造吗？不会 new会调用构造
    //new运算符，malloc是函数
    // t同样释放堆区域的空间  手动释放


//    malloc配合free用 delete也是运算符，要配合new用
//    Person person;
    delete person;
    system("pause");
}

void test03(){
//     //无法释放p
    void *p = new Person;
    delete p;
}
void test04(){
//    0 1     10  2
    Person *pArray = new Person[10];
    char *name = (char *)malloc(1000);
    if(name){
//        申请成功
    }
    delete[]pArray;
}
int main1() {
//    Person   p;  //栈区   不用自己释放
    test01();
}
int main() {
//    Person   p;  //栈区   不用自己释放
    test04();

//    Person person;

}
#include <iostream>
#include <string.h>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "new Person" << endl;
    }
    Person(int a)
    {
        cout << "Person  int " << endl;
    }
    ~Person()
    {
        cout << "析构 delete Person" << endl;
    }
};
void test01(){
//    堆区开辟内存 ==malloc（size）  强转指针(比如 (char *) malloc(strlen(name) + 1)
//new不需要传递对象的大小，返回声明的类型，同样是一个指针指针
    Person *person = new Person;
    //所有new出来的对象，都会返回该类型的指针
    //malloc返回void*还要强转
    //malloc会调用构造吗？不会 new会调用构造
    //new运算符，malloc是函数
    // t同样释放堆区域的空间  手动释放


//    malloc配合free用 delete也是运算符，要配合new用
//    Person person;
    delete person;

    //这里不能用delete
    //Person person2 =  Person();
    //delete person2;
    system("pause");
}

void test03(){
    //这里p2会被释放
    Person *p2 = new Person;
    delete p2;
    // 无法释放p
    void *p = new Person;
    delete p;
}
void test04(){
    Person *pArray = new Person[10];
    char *name = (char *)malloc(1000);
    if(name){
        cout << "申请成功" << endl;
//        申请成功
    }
    delete pArray;
    //这个才能把数组全部释放掉
    delete[]pArray;

}
int main1() {
//    Person   p;  //栈区   不用自己释放
    test01();
}
int main() {
//    Person   p;  //栈区   不用自己释放
//    test01();
//    test03();
    test04();


}
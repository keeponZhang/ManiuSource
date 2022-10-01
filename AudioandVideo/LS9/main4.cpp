#include <iostream>
#include <string.h>
using namespace std;

class Person{
public:
    int age;
    char *name;
public:
////    构造参数声明
    Person(){
        cout << "new person " << endl;
        }
    Person(char *name ,int age){
        cout << "new person int a, int b" << endl;
        this->age = age;
//        +1    /0
        this->name =(char *) malloc(strlen(name)+1);
        strcpy(this->name, name);
    }
//    析构函数  onDestyroy 没有重载  不需要   malloc   new   对象释放掉
//常量引用 重写
    Person(const Person  &person){
        cout << "const Person  int a" << endl;
        this->age = person.age;
        this->name =(char *) malloc(strlen(person.name)+1);
        strcpy(this->name, person.name);
    }
//重写拷贝函数
    ~Person(){
//        必须是无参
        cout << "delete  person " <<this->age<< endl;
//        第二个person、 对象 变量  静态变量
        if (this->name != NULL) { //为空1  不为空 2
            free(name);
            name = NULL;
        }
    }

};

int main() {
//    括号法实例化对象
    Person p("david", 12);
    cout << "name: "<<p.name<<" age :" <<p.age<< endl;
//
//    Person &p3 = p;
//    Person p2(p3);//p2   拷贝函数  p2  先释放1   p 先释放 2
    Person p2(p);
}
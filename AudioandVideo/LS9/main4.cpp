#include <iostream>
#include <string.h>

using namespace std;

class Person {
public:
    int age;
    char *name;
    char tag;
public:
////    构造参数声明
    Person() {
        cout << "new person " << endl;
    }

    Person(char *name, int age) {
        cout << "new person char *name, int age" << endl;
        this->age = age;
        this->name = (char *) malloc(strlen(name) + 1);
        strcpy(this->name, name);
    }
    Person(char *name, int age,char tag) {
        cout << "new person char *name, int age tag= " <<tag << endl;
        this->age = age;
        this->tag = tag;
        this->name = (char *) malloc(strlen(name) + 1);
        strcpy(this->name, name);
    }

//    析构函数  onDestroy 没有重载  不需要   malloc   new   对象释放掉
//常量引用 重写
//    Person(const Person &person) {
//        cout << "拷贝函数const Person  const &person :"<<person.tag << endl;
//        this->age = person.age;
//        this->name = (char *) malloc(strlen(person.name) + 1);
//        strcpy(this->name, person.name);
//    }

//重写拷贝函数
    ~Person() {
//        必须是无参
//        cout << "delete  person " << this->tag << endl;
//        第二个person、 对象变量
        if (this->name != NULL) {
            cout << "delete  this->name != NULL tag="<< this->tag<<" &name"<<&name<< endl;
            free(name);
            name = NULL;
        }
    }

};

int main() {
//    括号法实例化对象
    Person p("david", 12,'p');
    cout << "name: " << p.name << " age :" << p.age << endl;
//  加一个引用没用的，不会调用拷贝函数
//    Person &p3 = p;
    cout << "-----------p2------------"<< endl;
    Person p2(p);

}
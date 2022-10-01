#include <iostream>
#include <string.h>
using namespace std;

class Person{
public:
    int a;
    int b;
    int c;
public:
////    构造参数声明
//    Person(int a, int b, int c) {
//        this->a = a;
//        this->b = b;
//        this->c = c;
//    }

    Person():a(10),b(20),c(30){
}
    Person(int a,int b,int c):a(a),b(b),c(c){

}
};

int main() {
//    Person   p;  栈区   不用自己释放
    Person p(1, 2, 3);
    cout << "a: "<<p.a<<" b :" <<p.b<< "  c: "<<p.c<< endl;
}
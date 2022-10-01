#include <iostream>
using namespace std;
class Person{
public:
////    构造参数声明

      Person(int a){
         cout << "new person int a" << endl;
    }
       Person(char* a){
        cout << "new double person int a" << endl;
    }
    Person(int a, int b) {
        cout << "new person int a, int b" << endl;
    }
//    析构函数  onDestyroy 没有重载
    ~Person(){
//        必须是无参
        cout << "delete person" << endl;
    }
};
//括号法
//
void test01(){
//    java Person person=new Person()
//实例化对象 也是声明  已经开辟内存 堆区 1  栈区 2  new malloc
//最简单的声明
//括号实例化对象
//    Person person;//person=person()
//    Person person1=10;

//    栈区开辟一个person对象  再赋值给person变量
//
}


int main1() {
    std::cout << "Hello, World!" << std::endl;
    test01();
    return 0;
}

int main2() {
    std::cout << "Hello, World!" << std::endl;
    //   显示法  new  堆区       栈区声明
    Person p3= Person(10);
    Person p4= Person(10,220);
    return 0;
}


int main3() {
    std::cout << "Hello, World!" << std::endl;
    //   隐式法  new  堆区       栈区声明
    int a = 10;
//    一个构造参数
    Person p3= 10;
    return 0;
}

void test02(){
//    Person person;//person=person()
    Person person1 = "a";
    system("pause");
}
int main() {
//    有1  没有 2  实例化了4 个 person
//    Person person[4];
//    test02();
//    Person person=10.0;
//    Person person1=10;
    Person person = 'c';
    return 0;
//显示法  Person person=Person()
//括号法  Person person()
// 隐士法  Person person=10
}
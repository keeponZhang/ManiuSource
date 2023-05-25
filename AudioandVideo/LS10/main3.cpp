#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
class PersonEmpty{

};
class Person{
private:
//    最大元素的整数倍
    int a = 10;
    //如果只有b，占一个字节
    char b = 'b';
    //static不占字节数
    static int e  ;
public:
    //方法不占字节
    void test(){

    }
};

struct PersonStructEmpty{

};
struct PersonStruct{
    double a = 10;
    char b = 'b';

};
struct PersonStruct2{
    double a = 10;

};

void testMain2() {
    printf("---------testMain2---------------\n");
    PersonEmpty   personEmpty;
    cout << "personEmpty size =  " << sizeof(personEmpty) << endl;

    PersonEmpty  * personEmpty1;
    cout << "*personEmpty1 size =  " << sizeof(personEmpty1) << endl;


    PersonStructEmpty   personStructEmpty;
    cout << "personStructEmpty size =  " << sizeof(personStructEmpty) << endl;

    PersonStructEmpty  * personStructEmpty1;
    cout << "*personStructEmpty1 size =  " << sizeof(personStructEmpty1) << endl;
}
void testMain3() {
    printf("---------testMain3---------------\n");
    Person   person;
    cout << "person size =  " << sizeof(person) << endl;

    Person  * person1;
    cout << "*person1 size =  " << sizeof(person1) << endl;


    Person  * person12 = new Person();
    cout << "new * person12 size =  " << sizeof(person12) << endl;

    PersonStruct personStruct;
    cout << "personStruct size =  " << sizeof(personStruct) << endl;
    PersonStruct2 personStruct2;
    cout << "personStruct2 size =  " << sizeof(personStruct2 ) << endl;
}
void testMain4() {
    printf("---------testMain4---------------\n");
}
void testMain5() {
    printf("---------testMain5---------------\n");
}
void testMain6() {
    printf("---------testMain6---------------\n");
}
void testMain7() {
    printf("---------testMain7---------------\n");



}
int main() {
    //testMain2();
    testMain3();
    //testMain4();
    //testMain5();
    //testMain6();
    //testMain7();
    return 0;
}

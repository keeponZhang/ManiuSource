#include <iostream>
#include "ArrayList.h"
#include "iostream"
using namespace std;
void test(ArrayList* arrayList){

}
int main() {
    std::cout << "Hello, World!" << std::endl;
//    ArrayList * arrayList = new ArrayList();
    ArrayList arrayList = ArrayList(5);
    arrayList.add(4);
    arrayList.add(6);
    arrayList.add(7);
    arrayList.add(9);
    arrayList.toString();

    arrayList.add(11);
    arrayList.add(12);
    arrayList.toString();
    cout << "get  " << arrayList.get(0) << endl;
    return 0;
}

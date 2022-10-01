#include <iostream>

//包名
//int a = 0;
namespace  namespaceA{
    int a = 10;
}
namespace  namespaceB{
    namespace namespaceC  {
        struct Teacher{
            int age = 30;
        };
    }
    int a = 10;
}

int main(){
//    访问a
//    int a=namespaceA::a;
//    int b=namespaceB::a;
    using namespace  namespaceA;
//    using namespace  namespaceB;
    int c =  a;
//    namespaceB::namespaceC::Teacher teacher;
    using namespace namespaceB::namespaceC;
    Teacher teacher;
    return 0;

}



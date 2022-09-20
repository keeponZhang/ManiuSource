#include <stdio.h>


int jia(int a, int b) {
    return a + b;
}
int jian(int a, int b) {
    return a- b;
}
void change(int (**p1)(int a,int b)){
    *p1 = jia;
}
int main() {
    int (*pn)(int a, int b) =jia;
    printf("reslut: %d\n ", pn(20,10));
    pn = jian;
    printf("reslut: %d\n ", pn(20,10));


    change(&pn);
    printf("reslut: %d\n ", pn(20,10));
//
//    函数改变变量    变量的地址
//  改变指针变量    指针的地址   二级指针
// pn函数   函数地址
    return 0;
}




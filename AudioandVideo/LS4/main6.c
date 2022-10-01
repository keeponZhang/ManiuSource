#include <stdio.h>


int jia(int a, int b) {
    printf("---------jia---------------\n");
    return a + b;
}
int jian(int a, int b) {
    printf("---------jian---------------\n");
    return a- b;
}
void change0(int (*p1)(int a,int b)){
    printf("---------change0---------------\n");
    p1 = jia;
}
void change(int (**p1)(int a,int b)){
    printf("---------change---------------\n");
    *p1 = jia;
}
int main() {
    int (*pn)(int a, int b) =jia;
    printf("reslut: %d\n ", pn(20,10));
    pn = jian;
    printf("reslut: %d\n ", pn(20,10));
    change0(pn);
    printf("reslut: %d\n ", pn(20,10));
    change(&pn);
    printf("reslut: %d\n ", pn(20,10));
//
//    函数改变变量，就要传变量的地址
//  改变指针变量，就要传 指针的地址，指针的地址也叫二级指针
// pn函数   函数地址
    return 0;
}




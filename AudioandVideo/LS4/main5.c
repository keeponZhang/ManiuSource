#include <stdio.h>


int jia(int a, int b) {
    printf("---------jia---------------\n");
    return a + b;
}
int jian(int a, int b) {
    printf("---------jian---------------\n");
    return a- b;
}
int cheng(int a, int b) {
    printf("---------cheng---------------\n");
    return a *b;
}
int chu(int a, int b) {
    printf("---------chu---------------\n");
    return a / b;
}



int main() {
    //函数指针数组 指针 非常强大，主要用来做观察者集合

    int *px[10];//指针数组

    //数组里面都是存放的指针，指针是函数指针
    int (*pn[4])(int a, int b) ={jia, jian, cheng, chu };//定义一个函数指针

    int a = 30;
    int b = 20;
    for (int i = 0; i < 4; i++) {
        printf("result:%d\n", pn[i](a, b));
    }
    return 0;
}




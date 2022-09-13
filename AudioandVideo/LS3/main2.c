#include <stdio.h>
#include <malloc.h>
#define David  99//宏变量
#define ADD(x,y) ((x)+(y))

//
const  int a;
//c 不行的    包名  main.c    不同文件
int test(){
    int c;
    int d;
    return c + d;
}
int main() {
    char buf[3] = "abc \0";
    printf("buf:%s\n",buf);
//    int a = 10;//a
//    int b = 20;
//    int c = 30;
//    int d = 40;
////预处理  10+20*30
    {
        int c = 30;
        int b = 30;
        int d = 30;
//        系统回收
    }
//    printf("hong = %d\n", ADD(10, 20)*30);
//    printf("b = %d\n", &b);
//    printf("c = %d\n", &c);
//    printf("d = %d\n", &d);
//
//
//    int *arr = malloc(16);
//    for (int i = 0; i < 4; ++i) {
//        printf(" arr   %p\n", (arr + i));
//    }
//    test();
//    int f;
    return 0;
}

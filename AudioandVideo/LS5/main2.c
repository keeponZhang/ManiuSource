#include <stdio.h>
#include "string.h"

//
void  main2(){
    int a = 2;
    int c = 6;
//    常量指针  const 在*前 常量指针  不能变指向内容
    const   int  *b = &a;


     b =&c;//常量指针 是不能复制的
    printf(" b %d", *b);
}

//------------指针常量-----------------  不能变指向
int main(){
    int a = 2;
    int b = 11;
    int *const c = &a;
    *c = 10;
//    c = &b;
    printf("c %d", *c);
}

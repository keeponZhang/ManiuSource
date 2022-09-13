#include <stdio.h>
#include <malloc.h>


void test01(){
    int *p1  = 99;
    printf("  befor p1------ %d\n", p1 );
    //这里运行取会报错
    //printf("  before *p1------ %d\n", *p1 );
    //99地址  1    数据  2
    int *p;   //定义一个地址的变量          变量时空的

    int a = 10;//实体的变量
    p = &a;

    int c = *p;//是取出指针变量的地址  所指向的值
    printf(" c ------ %d\n",  c);
    printf(" &a ------ %p\n",  &a);

    printf(" p ------ %p\n",  p);
    printf("&p ------ %p\n",  &p);

//*  左边


    //指针的大小是固定的， 8个字节
    printf("sizeof------ %d\n", sizeof(p));

//    野指针
//     printf(" ---  %d", *p);


}
int main() {
    test01();
    return 0;


}

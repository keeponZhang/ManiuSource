#include <stdio.h>
#include <malloc.h>
#include <cdoex.h>
void test01(){
    int a = 0xaabbccdd;

    int *p1 = &a;

    //取1个字节
    char *p2 = &a;

    //可以正常取出来
    printf("*p1 %x\n", *p1);
    //ffffffdd
    printf("*p2 %x\n", *p2);

//    地址

    printf("p1  =%d\n", p1);

    printf("p2  =%d\n", p2);

    //指针类型决定步长长度
    //这里会加4个字节，因为是int类型
    printf("p1  =%d\n", p1+1);
   //这里会加1个字节，因为是char类型
    printf("p2  =%d\n", p2+1);
}
int main() {
    test01();
    return 0;


}

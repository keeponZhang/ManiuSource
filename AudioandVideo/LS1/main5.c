#include <stdio.h>
#include <malloc.h>
#include <cdoex.h>

//数组指针  数组 存放的是指针类型
void test01(){

    int a = 10;
    int b=20;
    int c = 30;
    int d = 40;
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;
    int *p4 = &d;
    int * arr[3] = {p1, p2, p3};//整形指针数组
    int * brr[4] = {p1, p2, p3,p4};//整形指针数组
    //指针类型加1是跟它是指向那种类型有关，

    printf("p1=%p \n", p1);//000000000022FDF4
    printf("p2=%p \n", p2);//000000000022FDF0
    printf("p3=%p \n", p3);//000000000022FDEC
    printf("sizeof(arr)=%d \n", sizeof(arr));//24
    printf("sizeof(brr)=%d \n", sizeof(brr));//32
    printf("（表示一个地址，这个地址指向的是一个指针数组）arr=%p \n", arr);//000000000022FDD0
    printf("（表示一个地址，这个地址指向的是一个指针数组） arr+1=%p \n", arr+1);//000000000022FDD8
    printf("（表示一个地址，这个地址指向的是一个指针数组） arr+2=%p\n", arr+2);//000000000022FDE0
    printf("（表示一个地址，这个地址指向的是一个指针数组） brr=%p \n", brr);//000000000022FDB0
    printf("（表示一个地址，这个地址指向的是一个指针数组） brr+1=%p \n", brr+1);//000000000022FDB8
    printf("（地址上的值，这里是整型指针数组，*arr 其实就是p1）*arr=%p \n", *arr);//000000000022FDF4
    printf("（*(arr+1) =p1） *(arr+1)=%p \n", *(arr+1));//000000000022FDF0
    printf("（**ar表示arr第一个存在地址所存的值）**arr=%d \n", **arr);//10
    printf("(p1的值（这里是个地址）)arr[0]=%p \n", arr[0]);//000000000022FDF4
    printf("(arr[0]==*arr）)arr[0]=%p *arr=%p \n", arr[0],*arr);//000000000022FDF4
    printf("(p1的值表示地址，这个地址存的值)*arr[0]=%d \n", *arr[0]);//10
//    *arr  arr[0]    *（arr+1）  arr[1]

    char *aa = arr;
    //指针可以互相转换 000000000022FDF4
    printf(" *((int *)aa)= %p \n", *((int *)aa));
}
//数组  指针
int main() {
    test01();
    return 0;


}

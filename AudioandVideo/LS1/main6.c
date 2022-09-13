#include <stdio.h>
#include <malloc.h>
#include <cdoex.h>
 int tableSizeFor(int cap) {
    int n = cap - 1;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return  n + 1;
}
//数组指针  数组 存放的是指针类型
void test01(){
//    数组指针  数组存放着指针     数组=指针
    int a[] = {1,2};
    int b[]={3,4};
    int c[] = {5};
    int * arr[3] = {a, b, c};//整形指针


    int * arr1[3] = {10, 10, 10};//整形指针
//
    printf("a=%p \n",a);
    printf("b=%p \n",b);
    printf("c=%p \n",c);
    printf("arr=%p \n",arr);
    //如果数组里面存的是指针，+1是+8，每个存地址的占8个字节
    printf("arr+1=%p \n",arr+1);
    printf("(*arr=a)*arr =%p \n",*arr);
    printf("(*arr=b) *(arr+1) =%p \n",*(arr+1));
    printf("**arr =%d \n",**arr);
    printf("arr[0][0]=%d \n",arr[0][0]);
    printf("arr[0][1]=%d \n",arr[0][1]);
    printf("arr[1][0]=%d \n",arr[1][0]);
    printf("arr[1][1]=%d \n",arr[1][1]);
    printf("arr[2][0]=%d \n",arr[2][0]);
    printf("arr[2][1]=%d \n",arr[2][1]);
}


//数组  指针
int main() {
    int a=tableSizeFor(33);
    printf("%d \n",a);
    test01();
    return 0;
}

#include <stdio.h>


void test(int array[] ,int size){
    for (int i = 0; i < size; ++i) {
        printf("value: %d\n", array[i]);
    }
}


int main() {
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    int  b[3] = {10, 20, 30};
//    test(b,6);
//    printf("Hello, World!\n");
//
//    int *c = b;
//    printf("c:0x%x\n",  c);
//    c++;
//    printf("*&c:0x%x\n",  c);
//// b 变量名   &b  指向数组的地址
//
//    printf("b:%p\n", b);
//    printf("&b:%p\n", &b);//&b
////    指向了一个首地址
////    指针指向类型
//
//    printf("*b=%d\n ", sizeof(*b));
//    printf("*&=%d\n ", sizeof(*&b));

//    数组 3节课 图形  一脸懵逼
//下表发  java
    for (int i = 0; i <3; i++)
        printf("arr[%d]=%d ", i, b[i]);
    printf("------------------------\n");
//    地址法


    for (int i = 0; i < 3; i++)
        printf("arr[%d]=%d ", i, *(b + i));


    printf("------------------------\n");

//指针法
    int *d = b;
    for (int i = 0; i < 3; i++)
        printf("arr[%d]=%d ", i, *(d + i));
    return 0;
}




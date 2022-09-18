#include <stdio.h>
#include <malloc.h>
#define David  99//宏变量
#define ADD(x,y) ((x)+(y))

int *get_str(){
    char  str[]  = "abcdedsgads"; //栈区
    return str;

}
//不能直接这样返回指针
int *get_str2(){
    int  str[4]  = {10,120,19,20}; //栈区
//    int  *str  =malloc(16); //栈区，
    return str;

}
int *get_str3(){
    int  *str  =malloc(16); //栈区，
    return str;

}
void test1(){
    char *arr = get_str();
    printf("----> arr 0x%x",  arr);
    //这里会导致崩溃
    printf("----> *arr %c",  *arr);
}
void test2(){
    int *arr = get_str2();
    printf("----> arr 0x%x",  arr);
    //printf("%d ", *arr);

}
void test3(){
    int *arr = get_str3();
    printf("----> arr 0x%x",  arr);
    printf("%d ", *arr);

}
void test4(){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int **arr=malloc(16);
    int **brr=malloc(sizeof(int*));
}
x
int main() {
    //test1();
    //test2();
    test3();
    return 0;
}

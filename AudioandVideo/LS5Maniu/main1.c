#include <stdio.h>
#include "string.h"
int main1() {
    printf("input str\n");
    while (1) {
//str  栈去  1   常量池 2
        char str[10];
        scanf("%s", str);//api
        printf("str=%s\n", str);
    }

    return 0;
}
int main2() {

    printf("input str\n");
//gets  scanf  输入设备获取    gets 空格当成内容 回车 输出
    char str[10];
    gets(str);
    printf("str=%s\n", str);
}

int main4() {
    printf("input str\n");
    while (1) {
        char str[10];
        fgets(str, 10, stdin);//fgets 输入 stdin 输入设备
        printf("str=%s\n", str);
    }

}
int main5() {
    printf("input str\n");//常量的不能修改了
//    常量指针 1  指针常量 2
    char *s1 = "abc";
    s1 = "asd";
    printf("str=%s\n", s1);

}

int main6(){
    char s1[] = "abc";// '\0'

    printf("sizeof return %d\n",strlen( s1));
//    s1
    printf("sizeof return %d\n",sizeof( s1));
}
int main7(){

    int arr[4] = {1, 2, 3, 4};

    printf("size  %d\n", sizeof(arr));
    char s1[]  = "aaaaaaaaaa";    //栈区

    strcpy(s1, "david");
    printf("str  %s\n",s1);
    printf("strlrn str %c\n",s1[9]);
    printf("strlrn size %d\n",strlen(s1));
    printf("strlrn size %d\n",sizeof(s1));
}
//stringbuffer


void mystrcat(char *s1,char * s2){
//    指针  java new string
    while(*s1)s1++;
//    修改了执行内容  david
    while(*s1++=*s2++);
}
int main8() {
    char s1[] = "abc";
    char s2[] = "123";
//行  1  不行 2  常量指针
//    char *s1 = "abc";
//    char *s2 = "123";
    mystrcat(s1, s2);
    printf("str[6]%d", s1[6]);
    printf("%s\n",s1);
}

int main(){
//字符串 本身一个一维数组
//字符串数组  二维数组    * const


//    常量指针  不能修改指向的内容  但是能够重新赋值(重新换一个指向)   const int *ptr;

//    指针常量     能修改指向的内容   不能够重新赋值(不能重新换一个指向)  int *const  p2
    int * const p9;
    char arr[4][6] = {"abc", "efg", "hij", "klm"};

//  指针常量 int *const  arr
//    arr[0] = "frg";// 不能够重新赋值(不能重新换一个指向)
    strcpy(arr[0], "aaaaa");// 能修改指向的内容
//arr[4][6]   指针常量

    printf("value %s\n",  arr[0]);
//数组指针     1    arr1  指针常量 1  常量指针  2

//--------------------常量指针--------------
//    常量指针  不能修改指向的内容  但是能够重新赋值(重新换一个指向)   const int *ptr;

//    指针常量     能修改指向的内容   不能够重新赋值(不能重新换一个指向)  int *const  p2
    int const *p6;
    char *arr1[4]={"abc", "efg", "hij", "klm"};
//    换一个指向
    char *arr5 = "ABC";
    arr1[0] = "ABC";//重定向  地址
//
    printf("value %s\n",  arr1[0]);
//修改指向内容
//    strcpy(arr1[0], "BBBBB");
    printf("value %s\n",  arr1[0]);
}
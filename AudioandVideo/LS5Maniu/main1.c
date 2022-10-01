#include <stdio.h>
#include "string.h"

int main0() {
    printf("---------main0---------------\n");
    printf("input str\n");
    char str[10];
    scanf("%s", str);//api
    printf("str=%s\n", str);
    return 0;
}

int main1() {
    printf("---------main1---------------\n");
    printf("input str\n");
    while (1) {
        //在栈区
        char str[10];
        scanf("%s", str);//api
        printf("str=%s\n", str);
        if (scanf("%s", str) == EOF) {
            break;
        }
    }
    return 0;
}

int main2() {
    printf("---------main2---------------\n");

    printf("input str\n");
//gets  scanf  输入设备获取    gets 空格当成内容 回车 输出
    char str[10];
    gets(str);
    printf("str=%s\n", str);
}

int main3() {
    printf("---------main3---------------\n");
    printf("input str\n");
    while (1) {
        char str[10];
        fgets(str, 10, stdin);//fgets 输入 stdin 输入设备
        printf("str=%s\n", str);
        if (scanf("%s", str) == EOF) {
            break;
        }
    }
}

//指针和 const 谁在前先读谁 ； *象征着地址，const象征着内容；
//谁在前面谁就不允许改变

//int const *p1 = &b; //const 在前，定义为常量指针
//常量指针是指指向常量的指针，顾名思义，就是指针指向的是常量，即，它不能指向变量，它指向的
//        内容不能被改变，不能通过指针来修改它指向的内容，但是指针自身不是常量，它自身的值可以改变，
//从而指向另一个常量。
//int *const p2 = &c; // *在前，定义为指针常量
//指针常量是指指针本身是常量。它指向的地址是不可改变的，但地址里的内容可以通过指针改变。它
//        指向的地址将伴其一生，直到生命周期结束。有一点需要注意的是，指针常量在定义时必须同时赋初值。
int main4() {
    printf("---------main4---------------\n");
    printf("input str\n");//常量的不能修改了
//    常量指针 类似char const *s1，指向的内容是无法改的
    char *s1 = "abc";
    //这里会报错，常量区的内容不能修改
    //gets(s1);
    //这样是可以的，这里是改变指向
    s1 = "asd";
    printf("str=%s\n", s1);

}

int main5() {
    printf("---------main5---------------\n");

}

int main6() {
    printf("---------main6---------------\n");

    char s1[] = "abc";// '\0'
    //3
    printf("sizeof return %d\n", strlen(s1));
//    4
    printf("sizeof return %d\n", sizeof(s1));
}

int main7() {
    printf("---------main7---------------\n");
    int arr[4] = {1, 2, 3, 4};
    printf("sizeof(arr)  %d\n", sizeof(arr));
    //栈区,是可以修改的
    char s1[] = "aaaaaaaaaa";
    char *b = "aa";
    printf("str origin  %s\n", s1);
    printf("strlen(s1)=  %d\n", strlen(s1));
    printf("sizeof(s1)= %d\n", sizeof(s1));
    printf("strlen(b)=  %d\n", strlen(b));
    printf("strlen(arr)=  %d\n", strlen(arr));
    strcpy(s1, "david");
    //打印会遇到\0结束
    printf("str change to david  %s\n", s1);
    printf("str change to david sizeof(s1)= %d\n", sizeof(s1));
    printf(" str s1[9]= %c\n", s1[9]);
    printf("strlen(s1)=  %d\n", strlen(s1));
    printf("sizeof(s1)= %d\n", sizeof(s1));
}
//stringbuffer


void mystrcat(char *s1, char *s2) {
//    指针  java new string
    while (*s1)s1++;
//    修改了执行内容  david
    while ((*s1++ = *s2++));
}

int main8() {
    printf("---------main8---------------\n");
    char s1[] = "abc";
    char s2[] = "123";
    printf("s1 before %s\n", s1);
    mystrcat(s1, s2);
    printf("str[6]%d", s1[6]);
    printf("s1 after %s\n", s1);
}

int main9() {
    printf("---------main9---------------\n");
    //这里会报错
    char *s1 = "abc";
    char *s2 = "123";
    printf("s1 before %s\n", s1);
    mystrcat(s1, s2);
    printf("str[6]%d", s1[6]);
    printf("s1 after %s\n", s1);
}


void test2() {
    printf("---------test2常量指针---------------\n");
    int a = 2;
    int c = 15;
    //常量指针（指向的内容不能改） 不能修改指向的内容  但是能够重新赋值(重新换一个指向)
    int const *b = &a;
    printf("before *b %d\n", *b);
    b = &c;
    printf("after *b %d\n", *b);

}

void test3() {
    printf("---------test3---------------\n");
    int a = 2;
    //指针常量 能修改指向的内容   不能够重新赋值(不能重新换一个指向)
    int *const p2 = &a;
    printf("before *b %d\n", *p2);
    //可以改变指向的内容
    *p2 = 16;
    printf("after *b %d\n", *p2);
}

void testOriginal() {
//字符串 本身一个一维数组
//字符串数组  二维数组    * const

    int *const p9;
    char arr[4][6] = {"abc", "efg", "hij", "klm"};

//  指针常量 int *const  arr

    strcpy(arr[0], "aaaaa");// 能修改指向的内容
//arr[4][6]   指针常量

    printf("value %s\n", arr[0]);
//数组指针     1    arr1  指针常量 1  常量指针  2

//--------------------常量指针--------------
//    常量指针  不能修改指向的内容  但是能够重新赋值(重新换一个指向)   const int *ptr;

//    指针常量     能修改指向的内容   不能够重新赋值(不能重新换一个指向)  int *const  p2
    int const *p6;
    char *arr1[4] = {"abc", "efg", "hij", "klm"};
//    换一个指向
    char *arr5 = "ABC";
    arr1[0] = "ABC";//重定向  地址
//
    printf("value %s\n", arr1[0]);
//修改指向内容
//    strcpy(arr1[0], "BBBBB");
    printf("value %s\n", arr1[0]);
}

void test4() {
    printf("---------test4---------------\n");
    //字符串 本身一个一维数组
    //字符串数组  二维数组
    char arr[4][6] = {"abc", "efg", "hij", "klm"};
    printf("arr[0]修改指向的内容前value %s\n", arr[0]);
    //指针常量  *const（能够修改指向的内容，但是不能重新赋值）
    //    arr[0] = "frg";
    strcpy(arr[0], "aaaaa");// 能修改指向的内容
    printf("arr[0]修改指向的内容后value %s\n", arr[0]);

    //有指针指针在后面，没有的在前面

    //常量指针，不能修改指向的内容  但是能够重新赋值(重新换一个指向)
    char *arr1[4] = {"abc", "efg", "hij", "klm"};
    printf("arr1[0]修改指向的内容前value %s\n", arr1[0]);
    arr1[0] = "keepon";
    //strcpy(arr1[0], "keepon2");// 不能 修改指向的内容
    printf("arr1[0]修改指向的内容后value %s\n", arr1[0]);
}

void test5() {
    printf("---------test5---------------\n");
}

void test6() {
    printf("---------test6---------------\n");
}

void test7() {
    printf("---------test7---------------\n");
}

int main() {
    //main0();
    //main1();
    //main2();
    //main3();
    //main4();
    //main5();
    //main6();
    //main7();
    //main8();
    //main9();
    //test2();
    //test3();
    test4();
    //test5();
    //test6();
    //test7();
    return 0;
}
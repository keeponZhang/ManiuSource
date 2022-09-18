#include <stdio.h>
#include <malloc.h>

const int a;//静态区
//c 不行的    包名  main.c    不同文件
extern int test() {

}

void test1() {
    int a = 0;//栈区
    int *p = &a;//int  *  指针指向类型 int  4
    int **temp = &p;  // int *    指针

    char **temp1 = &p;//指针可以强转    指针自身类型 char **   指针指向类型  char*


    printf("---------\n");
    printf("temp1:%p\n", temp1);
    temp1++;
    printf("temp1:%p\n", temp1);

    printf("---------\n");
    printf(" temp * sizeof= %d\n", sizeof(int *));
    printf("temp:%p\n", temp);
    temp += 2;
    printf("temp:%p\n", temp);
    int **p1;// 指针 自身类型   int **  指针指向类型   int *，   指针值的内容
    p = &a;
    *p = 10;
}

void test2() {
    //int* 不是地址8吗   为什么打印+1   int 是+4
    int arr[4] = {1, 2, 3, 4};//指针自身的类型   int * [4]  自身类型    //指针指向类型    int 类型
    int *arr1 = arr;
    printf("---arr:%p\n", arr);
    printf("---arr1:%p\n", arr1);
    //变量名是个常量，不能相加
    //arr++;
    printf("---arr++:%p\n", arr1 + 1);
    arr1++;
    printf("---arr1++:%p\n", arr1);
    printf("---------\n");
    int charP[5] = {'C', 'D', "F", "G", "G"};
    //    元素长度+ 类型大小  (int 4  char 1)
    int  (*p3)[3] = &charP;//指针自身的类型 int (*)[3]    指向类型   int  ()[3]   新的类型    3*4=12
    printf("p3:%p\n", p3);
    p3++;
    printf("p3:%p\n", p3);

    //指向类型可以是个数组(这里构建新的指向类型)
    char  (*p4)[3] = &charP;//指针自身的类型 char (*)[3]    指向类型   char  ()[3]   新的类型    3*1=3
    printf("p4:%p\n", p4);
    p4++;
    printf("p4:%p\n", p4);


    char  (*p42) [3]= &charP;//指针自身的类型 char (*)[3]    指向类型   char  ()[3]   新的类型    3*1=3
    printf("p4:%p\n", p4);
    p4++;
    printf("p4:%p\n", p4);
    printf("---------\n");

    char *p41 = &charP;//指针自身的类型 char (*)[3]    指向类型   char  ()[3]   新的类型    3*1=3
    printf("p41:%p\n", p41);
    p41++;
    printf("p41:%p\n", p41);
    //
    printf("---------\n");
    //这样存的是指针
    char *p5[5] = {'K', 'e', "e", "p"};
    printf("p5:%p\n", p5);
    printf("p5+1:%p\n", p5+1);
    printf("*p5:%c\n", *p5);
    printf("*(p5+1):%c\n", *(p5+1));
    printf("---------\n");

    char p6[5] = {'K', 'e', "e", "p"};
    printf("p6:%p\n", p6);
    printf("p6+1:%p\n", p6+1);
    printf("*p6:%c\n", *p6);
    printf("*(p6+1):%c\n", *(p6+1));
}

int main() {

    int arr4[3] = {10, 20, 30};
//    栈区 1  堆区 2  自己释放
    char *b = malloc(100);
//   p--   指针步长 n*sizeof(指针指向类型) 。   指针自身类型  1     指针指向类型     2


    //test1();
    test2();


    return 0;
}

#include <stdio.h>
#include <malloc.h>

const  int a;//静态区
//c 不行的    包名  main.c    不同文件
extern  int test(){

}
int main() {
    int a=0;//栈区
    int arr4[3] = {10, 20, 30};
//    栈区 1  堆区 2  自己释放
    char *b = malloc(100);
//   p--   指针步长 n*sizeof(指针指向类型) 。   指针自身类型  1     指针指向类型     2
    int *p=&a;//int  *  指针指向类型 int  4
    int **temp = &p;  // int *    指针

    char **temp1 = &p;//指针可以强转    指针自身类型 char **   指针指向类型  char*


    printf("---------" );
    printf("temp1:%p\n", temp1);
    temp1++;
    printf("temp1:%p\n", temp1);

    printf("---------" );

    printf(" temp * %d\n", sizeof(int *));
    printf("temp:%p\n", temp);
    temp+=2;
    printf("temp:%p\n", temp);
    int **p1;// 指针 自身类型   int **  指针指向类型   int *，   指针值的内容
    p = &a;
    *p = 10;
   // C99;
    char  *x1;
//int* 不是地址8吗   为什么打印+1   int 是+4
    char arr[4] = {1, 2, 3, 4};//指针自身的类型   int * [4]  自身类型    //指针指向类型    int 类型
    char *arr1 = arr;
    printf("---arr1++:%p\n", arr1);
    arr1++;
    printf("---arr1++:%p\n", arr1);
    int charP[5]={ 'C','D',"F","G","G"};

//    元素长度+ 类型大小  (int 4  char 1)
    int  (*p3)[3] = &charP;//指针自身的类型 int (*)[3]    指向类型   int  ()[3]   新的类型    3*4=12
    printf("p3:%p\n", p3);
    p3++;
    printf("p3:%p\n", p3);

    return 0;
}

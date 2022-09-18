#include <stdio.h>
#include <malloc.h>

#define David  99//宏变量
#define ADD(x, y) ((x)+(y))

void print_array(int **arr, int n) {
    //括号优先级大于*号优先级
    for (int i = 0; i < n; i++) {
        //arr[i]等于 *(arr + i)
        printf(" arr[i]   = %p\n", arr[i]);
        printf(" *(arr+i) = %p\n", *(arr + i));

        printf(" *(arr[i])=%d\n", *(arr[i]));
        printf("**(arr + i)=%d\n", **(arr + i));
        printf("-----------------------\n");
//        释放
    }
}

void test4() {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int **arr = malloc(16);
    int **brr = malloc(sizeof(int *));
}

void test5() {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    int n = 5;
    int **arr = malloc(sizeof(int *) * n);
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;
    arr[4] = &e;
}

void test1() {
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    int a4 = 40;
    int a5 = 50;
    int n = 5;
    int **arr = malloc(sizeof(int *) * n);
    arr[0] = &a1;
    arr[1] = &a2;
    arr[2] = &a3;
    arr[3] = &a4;
    arr[4] = &a5;
    print_array(arr, 5);
    free(arr);
}

void test() {
    int b = 10;
    int *p1 = &b;
    int **p2 = &p1;//二级指针
}

int main() {
    test();
    test1();
    return 0;
}

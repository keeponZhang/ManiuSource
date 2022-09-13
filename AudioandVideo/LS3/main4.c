#include <stdio.h>
#include <malloc.h>
#define David  99//宏变量
#define ADD(x,y) ((x)+(y))

void print_array(int **arr, int n) {

    for (int i = 0; i < n;i ++){
        printf("%d\n", *(arr[i]));
        printf("%d\n", **(arr+i));
//        释放
    }
}
void test(){
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    int a4 = 40;
    int a5 = 50;
    int n = 5;
    int **arr=malloc(sizeof(int *)*n);
    arr[0] = &a1;
    arr[1] = &a2;
    arr[2] = &a3;
    arr[3] = &a4;
    arr[4] = &a5;
    print_array(arr, 5);
    free(arr);
}
int main() {
//    int b = 10;
//    int *p1 = &b;
//    int **p2 = &p1;//二级指针
    test();
    return 0;
}

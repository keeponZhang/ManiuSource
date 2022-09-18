#include <stdio.h>
#include <malloc.h>

#define David  99//宏变量
#define ADD(x, y) (x)+(y)
#define ADD2(x, y) ((x)+(y))
void test2(){
    printf("hong = %d\n", ADD(10, 20)*30);
    printf("hong = %d\n", ADD2(10, 20)*30);
}
//
const int a;

//c 不行的    包名  main.c    不同文件
int test() {
    int c;
    int d;
    return c + d;
}

void test1() {
    //上面的是高地址
    int b = 30;
    int c = 30;
    int d = 30;
    printf("b = %d\n", &b);
    printf("c = %d\n", &c);
    printf("d = %d\n", &d);
        int *arr = malloc(16);
    //    这个是后面的大
    for (int i = 0; i < 4; ++i) {
        printf(" arr   %p\n", (arr + i));
    }
    printf("-----------------------\n");

}
void test3(){
    char buf[3] = "abc \0";
    //会把后面几个打印出来
    printf( "buf:%s\n", buf);
}
int main() {
    //test1();
    //test2();
    //test3();
////预处理  10+20*30
    {
        int c = 30;
        int b = 30;
        int d = 30;
//        系统回收
    }

//
//

//    test();
//    int f;
    return 0;
}

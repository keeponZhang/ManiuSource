#include <stdio.h>

void test0(int array[]) {
    for (int i = 0; i < 10; ++i) {
        printf("value: %d\n", array[i]);
    }
}

void test(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("value: %d\n", array[i]);
    }
}

void test1() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    test0(arr);
}

void test2() {
    int b[3] = {10, 20, 30};
    int *c = b;
    //相差4（当前指针指向的是数组第一个地址，c+1表示指向下一个地址，int是整型，1个占4个字节）
    printf("before sizeof(c):%d\n",sizeof(c));
    printf("c:0x%x\n", c);
    c++;
    printf("----------执行c++--------------\n",b);//&b
    printf("*&c:0x%x\n", c);
    printf("*c:%d\n", *c);
    printf("after sizeof(c):%d\n",sizeof(c));
    //// b 变量名   &b  指向数组的地址
    printf("----------指向地址--------------\n",b);//&b
    printf("b:%p\n", b);
    printf("&b:%p\n", &b);//&b
    //不能被赋值
    //&b =&b+1;
    printf("----------指向类型--------------\n",b);//&b
    ////    指向了一个首地址
////    指针指向类型
    printf("sizeof(*b)=%d\n ", sizeof(*b));
    printf("sizeof(*&b)=%d\n ", sizeof(*&b));

    printf("------------------------\n",b);//&b
    int (*d)[3] = &b;
    printf("d:0x%x\n ", d);
    printf(" sizeof(*d):%d\n ", sizeof(*d));
    d++;
    //这种相差12
    printf(" sizeof(*d):%d\n ", sizeof(*d));
    printf("d++:0x%x\n ", d);
}
void test3() {
//下标法  java
    printf("---------下标法---------------\n");
    int b[3] = {10, 20, 30};
    for (int i = 0; i < 3; i++)
        printf(" arr[%d]=%d \n", i, b[i]);

}
void test4() {
//    地址法
    printf("---------地址法---------------\n");
    int b[3] = {10, 20, 30};
    for (int i = 0; i < 3; i++)
        printf(" arr[%d]=%d \n", i, *(b + i));
}
void test5() {
    printf("---------指针法---------------\n");
    //指针法
    int b[3] = {10, 20, 30};
    int *d = b;
    for (int i = 0; i < 3; i++)
        printf("arr[%d]=%d \n", i, *(d + i));
}

int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}




#include <stdio.h>


void test0() {
    //    虚拟机 有 1 没有 2     肯定有   虚拟机 指针
//上帝视角  ，
    int p;//变量     1  2    4 5 6
    int a = 10;
    int *p10 = &a;//p10  地址 0x0111121FFF
//指针类型  决定了  + 多少  =n * sizeof(指针类型)  1*1
    long *p1;//指针 单个指针变量
//    printf("p1 :%p \n", p1);
//    p1++;
//    printf("p1 :%p \n", p1);
    int p2[2];
    int *p4[4];
    int *p11 = p4;
    char **p12;
//指向类型
    int *ptr1;//int  4  char *ptr1  1  sizeof(指向的类型)

    int b = 10;
    int *x = &b;
    int **y = &x;
    char **ptr;// 指向的类型     int *
    // 指向的类型     char *
//    数组指针    指针
//   1  8个字节  2  *p12 指针
    printf("p12--- :%d \n", sizeof(*y));

    //p5是单个指针比变量
    int (*p5)[4];
//    一般情况从右向左结合
// 相邻情况
//    int *p5;
//这个指针的自身的类型是什么？指针指的类型是什么？该指针指向了哪里？
    int *p6;//指针类型 int *    指向的类型 int
    char *p7;//指针类型 char *   char
    int **p8;//指针类型 int *  4  1 8个字节  2    指向的类型也是指针

    int c[9] = {1, 2, 9, 4, 5, 6, 7, 8, 9};
    int d[4] = {2293240, 2293244, 2293248, 13};

    int (*p9)[4];  //int()[3] 数组指针，指向的是一个数组

    printf("Hello, World!\n");

}

void test01() {
    int a = 10;
    int b = 20;
    int c = 30;
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;
    int arr[3] = {a, b, c};//整型数组
    int *brr[3] = {p1, p2, p3};//整形指针数组
    int (*crr)[] = arr;//是一个指针，指向数组
    printf("sizeof(a)=%d \n", sizeof(a));//4
    printf("sizeof(p1)=%d \n", sizeof(p1));//8
    printf("arr=%p \n", arr);//000000000022FDE8
    printf("*arr=%d \n", *arr);//10
    printf("arr=%p \n", arr);//000000000022FDE8
    printf("brr=%p \n", brr);//000000000022FDD0
    printf("crr=%p \n", crr);//000000000022FDE8
    printf("(crr等于*crr)*crr=%p \n", *crr);//000000000022FDE8
    printf("**crr=%d \n", **crr);//10
    printf("sizeof(arr)=%d \n", sizeof(arr));//12
    printf("sizeof(crr)=%d \n", sizeof(crr));//8
}

void test02() {
    int a = 10;
    int b = 20;
    int c = 30;
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;
    int arr[3] = {a, b, c};//整型数组
    int *brr[3] = {p1, p2, p3};//整形指针数组
    int *x = &a;
    int **y = &x;

    printf("arr=%p \n", arr);
    printf("brr=%p \n", brr);
    printf("arr+1=%p \n", arr + 1);
    printf("brr=%p \n", brr + 1);
    printf("x=%p \n", x);
    printf("y=%p \n", y);
    printf("x+1=%p \n", x + 1);
    printf("y=%p \n", y + 1);
}

void test03() {
    char a[20] = {'a', 'b', 'c', 'd', 'e'};
    int *ptr = (int *) a; //强制类型转换并不会改变a 的类型
    ptr++;
    printf("char %c\n", *a);
    printf("char %c\n", *ptr);
}

void test04() {
    int array[4] = {0};
    int *ptr = array;
    for (int i = 0; i < 4; i++) {
        (*ptr) = i;
        ptr++;
    }
    for (int i = 0; i < 4; ++i) {
        printf("value: %d\n", *(array + i));
        //这里相差4
        printf("value: %p\n", (array + i));
    }
    //printf("ptr : 0x%x\n", ptr );
    //printf("ptr : %d\n", *(ptr-1) );
}

void test05() {
    char a[20] = "You_are_a_girl";
    int *ptr = (int *) a;
    printf("* ptr addr %p\n", ptr);
    ptr += 1;
    printf("* ptr addr %p\n", ptr);
    printf("* ptr=%c\n", *ptr);

    printf("a= %p\n", a);
    printf("a+1 %p\n", a+1);
    printf("*a= %c\n", *a);
    printf("*(a+1) %c\n", *(a+1));
}

void test06() {
    char a[20] = "You_are_a_girl";
    char *p = a;
    char **ptr = &p;
    printf("a=0x%x\n", a);
    printf("p=0x%x\n", p);
    printf("*p=%c\n", *p);
    printf("ptr=0x%x \n", ptr);
    printf("*ptr=0x%x \n", *ptr);
    printf("**ptr=%c \n", **ptr);


    printf("before ptr= 0x%x\n", ptr);
    printf("size(*ptr)= %d\n", sizeof(*ptr));
    ptr++;
    printf("after ptr= 0x%x\n", ptr);
    //printf("ptr= %c\n", **ptr);

    printf("before p= 0x%x\n", p);
    printf("size(*p)= %d\n", sizeof(*p));
    p++;
    printf("after p= 0x%x\n", p);
}

int main() {
    //test0();
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();

    return 0;
}
#include <stdio.h>


void testOriginal() {
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf("-----------------\n");


    printf("-----------------\n");//3*12

    printf("-----------------\n");


//   数组取值



//    printf(" value %d\n ",*(*(p+1))+1);



}
void test2() {
    printf("---------test2---------------\n");
    //    10个字节
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
//    a &a *a
    printf("&a:%p\n", &a);
    printf("a:%p\n", a);
    printf("*a:%p\n",*a);

    printf("&a:%d\n", &a);
    printf("a:%d\n", a);
    printf("*a:%d\n",*a);
}
void test3() {
    printf("---------test3---------------\n");
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf("sizeof(*&a) = %d \n", sizeof(*&a));
    //相差48个字节
    printf(" &a   = %p \n",  &a );
    printf(" &a+1 = %p \n ", &a+1);
    // 相差48个字节
    printf(" &a   = %d \n",  &a );
    printf(" &a+1 = %d \n ", &a+1);

}
void test4() {
    printf("---------test4---------------\n");
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf("sizeof(*a)  =%d \n", sizeof(*a));
    //相差16个字节
    printf("a    = 0x%x \n",  a );
    printf("a+1  = 0x%x  \n ", a+1 );
    printf("a    = %d  \n",  a );
    printf("a+1  = %d  \n", a+1 );
}
void test5() {
    printf("---------test5---------------\n");
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf(" sizeof(**a)   = %d\n ", sizeof(**a));
    printf("a= %d\n ",  **a );
    printf("a+1= %d\n ", **a+1);
}
void test6() {
    printf("---------test6 下标法---------------\n");
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf("a[1][0] value = %d\n ", a[1][0]);

}
//    指针法 数组指针  p  一行的首地址     &p 整个数组    *p 单个元素
void test7() {
    printf("---------test7 指针法---------------\n");
//** 数组元素 p
    int a[3][4] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11, 12};
    printf("a    = %d  \n", a );
    printf("a+1    = %d  \n", a+1 );
    int (*p)[4]=a;
    //相差16
    printf("---------p+1---------------\n");
    printf("sizeof(*p)    = %d  \n", sizeof(*p) );
    //指向第一行地址
    printf("p    = %d  \n", p );
    //指向第二行地址，第一个（相差16）
    printf("p+1  = %d  \n", p+1 );
    //相差4，因为 *p转成一维数组指向了
    printf("---------*p+1---------------\n");
    printf("sizeof(**p)    = %d  \n", sizeof(**p) );
    //指向第一行地址 第一个
    printf("*p    = %d  \n", *p );
    //指向第一行地址 第而个
    printf("*p+1    = %d  \n", *p+1 );
    //
    printf("---------*(p+1)---------------\n");
    //指向第一行，第一个
    printf("*p    = %d  \n", *p );
    //指向第二行，第一个
    printf("*(p+1)    = %d  \n", *(p+1) );
    printf(" sizeof(*(p+1))     = %d  \n", sizeof(**(p+1)) );
    printf("---------value---------------\n");
    //1 指第一行第一个
    printf(" **(p) value %d \n", **(p));
    //5 指向第二行第一个
    printf(" **(p) value %d \n", **(p + 1));

}
void test8(){
    printf("---------test8---------------\n");
    int a[3][4] = {1, 2, 3, 4, 5,8, 7, 8, 9, 10, 11, 12};
    int (*p)[4]=a;
    //相当于下面这样
    //int (*p)[4]={{1, 2, 3, 4}, {5,6, 7, 8}, 9, {10, 11, 12}};
    //取出6
    printf(" value %d\n ",*(*(p+1)+1));
    //取出5再加1
    printf(" value %d\n ",*(*(p+1))+1);
//    混着用
// 数组 执政
    printf("---------for---------------\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++)
            //理解的重点是上课笔记的图，*p  （*（p+1)））可以理解成中间的虚拟数组，存的是地址，
            // 这个地址指向的是一维数组，（*（p+1)））+j，可以理解在指向的一维数组中移动，再取*为取数组的内容
            printf("value :%d\n",*(*(p+i)+j));
    }
}
int main() {
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    test8();



    return 0;
}




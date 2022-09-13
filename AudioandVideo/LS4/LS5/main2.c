#include <stdio.h>



int main() {
//    10个字节
    int a[3][4] = {1, 2, 3, 4, 5,8, 7, 8, 9, 10, 11, 12};

//    a &a *a

    printf("&a:%p\n", &a);
    printf("a:%p\n", a);

    printf("*a:%p\n",*a);
    printf("-----------------\n");
    printf("*&a=%d\n ", sizeof(*&a));
    printf("a=0x%x ",  &a );
    printf("a+1=0x%x\n ", &a+1);


    printf("-----------------\n");//3*12
    printf("*&a=%d\n ", sizeof(*a));
    printf("a=0x%x ",  a );
    printf("a+1=0x%x\n ", a+1);
    printf("-----------------\n");
    printf("**a=%d\n ", sizeof(**a));
    printf("a= %d ",  **a );
    printf("a+1= %d\n ", **a+1);

//   数组取值
    printf(" value %d\n ", a[1][0]);

//    指针法 数组指针  p  一行的首地址     &p 整个数组    *p 单个元素  p + 1
//** 数组元素 p
    int (*p)[4]=a;
    printf(" value %d\n ", **(p + 1));

//    printf(" value %d\n ",*(*(p+1))+1);


    printf(" value %d\n ",*(*(p+1)+1));
    printf(" value %d\n ",*(*(p+1))+1);

//    混着用
// 数组 执政
//
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++)
            printf("value :%d\n",*(*(p+i)+j));
    }


    return 0;
}




#include <stdio.h>
#include <malloc.h>
#include <cdoex.h>

void test01() {
    int c[9] = {1, 2, 9, 4, 5, 6, 7, 8, 9};
    int d[4] = {2293240, 2293244, 2293248, 13};

    //int *p = c;
    int *p = &c[2];
    int *c1= &c[1];
    int *c2= &c[2];
    int a;
//    c   常量  =a 只能够读 不能写
//    c = &a;
//    数组是一个比较特殊的额指针
//  第2个元素

    printf("sizOf= %d\n", sizeof(c));
    printf("地址c= %p\n", c);
    printf("第二个元素 %d \n", *(c + 1));
    printf("第三个元素 %d \n", *(c + 2));
    printf("地址c+1= %p\n", c+1);
    printf("地址c+2= %p\n", c+2);
    printf("地址*(c+1）= %d\n", *(c+1));
    printf("地址*（c+2）= %d\n", *(c+2));
    printf("地址c1= %p\n", c1);
    printf("地址c2= %p\n", c2);

    printf("地址d+1= %p\n", d);
    printf("地址d+1= %p\n", d+1);
    printf("地址d+2= %p\n", d+2);

    printf("p的地址 &p=  %p\n",&p);
    printf("p是存地址的，存的值为p =  %p\n",p);
    printf("p是存地址的，存的的值指向的地址的值为*p =  %p\n",*p);
    printf(" &c=  %p\n", &c);//不一样  1 一样  2
    printf("&c[0] =%p\n", &c[0]);

   int *p2 = c;
//数组=指针   指针=数组
    for (int i = 0; i < 8; i++) {
        //p2+1表示地址上加上4个字节
        //下面三个是相等的
        printf(" *(p2 + i) = %d \n", *(p2 + i));
        printf(" c[i]=%d \n", c[i]);
        printf(" *(c + i)=%d \n", *(c + i));
        printf("-------------------%d\n",i);
    }
}

//数组  指针
int main() {
    test01();
    return 0;


}

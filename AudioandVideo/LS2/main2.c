#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main() {
//    Person person

    int a = 0;
//NULL  =0
    int *p;//不加 1   加2
    int d = 100;
    int *p2 = &d;//不加 1   加2
    printf("p---%p \n", p);
    printf("p2---%p \n", p2);
    //找不到物理内存，会崩溃
    //*p = 10;
    //printf("*p2---%d \n", *p2);
    int keepon = *p2 ;

    printf("keepon---%d \n", keepon);
    *p2 = 1000;
    printf("keepon---%d \n",   *p2);
    //if(person!=null){}
// n* sizeof(char)
    int * arr= malloc(16);
    memset(arr, 0, 16);
    //int * arr= calloc(2, 16);

    for (int i = 0; i < 4; ++i) {
        printf("int i %d:  value: %d \n",i,*(arr+i));
        printf("int i %d:  value: 0x%x \n",i, (arr+i));
    }
    printf("---------------------------\n",arr);
    char * brr= malloc(16);
    memset(arr, 0, 16);
    //int * arr= calloc(2, 16);

    for (int i = 0; i < 4; ++i) {
        printf("char i %d:  value: %d \n",i,*(brr+i));
        printf("char i %d:  value: 0x%x \n",i, (brr+i));
    }
//
//    /**
//     */
    free(arr);
//    arr = NULL;
//    if (arr) {
//    }
//    printf(" arr  0x%x \n",arr);
//arr 指针 悬空指针

}

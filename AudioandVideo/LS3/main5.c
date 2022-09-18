#include <stdio.h>
#include <malloc.h>

#define David  99//宏变量

void allocateSpace(int **p) {
//    sizeof(int)  4个字节
    int *temp = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        temp[i] = 100 + i;
    }
//    *p 一级指针
    *p = temp;
    printf("allocateSpace temp=%p\n", temp);
    printf("allocateSpace *p=%p\n", *p);
}

void allocateSpace2(int *p) {
//    sizeof(int)  4个字节
    int *temp = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        temp[i] = 100 + i;
    }
//    *p 一级指针(传一级指针不行，找不到地址，所以修改不了该地址指向的内容)
    *(&p) = temp;

}

void allocateSpace3(int *p) {
//    sizeof(int)  4个字节
    int *temp = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        temp[i] = 100 + i;
    }
    printf("allocateSpace3 p=%p\n", p);
    printf("allocateSpace3 &p=%p\n", &p);
    //这里赋值后会相等，但是外面那个不会改变
    *(&p) = temp;
    printf("allocateSpace3 temp=%p\n", temp);
    printf("allocateSpace3 p=%p\n", p);
}


void freeArray(int **pArray, int n) {
    for (int i = 0; i < n; ++i) {
        printf("freeArray addr i=%d  %p \n", i,(*(pArray + i)));
        //free((*pArray)[i]);
        //free((*(pArray + i)));
        //free(*(pArray+i));
    }
}
//适合二级指针
void freeArray2(int **pArray, int n) {
    for (int i = 0; i < n; ++i) {
        //这个是错误的
        printf("freeArray addr i=%d %p   ",i,(*pArray)[i]);
        free((*pArray)[i]);
        //free((*(pArray + i)));
//        free(*(pArray+i))
    }
}
void freeArray3(int **pArray, int n) {
    for (int i = 0; i < n; ++i) {
        //pArray[i] 就是 int*类型的
        printf("freeArray addr i=%d %p   ",i,pArray[i]);
        free((pArray)[i]);
    }
}

void print_array(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        //这里 (*arr)是重点
        printf("print_array addr %d\n", (*arr)[i]);
        printf("print_array addr %p\n", arr+i);
    }
}

void print_array2(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("print_array2 i=%d addr %d\n", i, (arr)[i]);
    }
}

void test1() {
    int *p = NULL;

    allocateSpace(&p);
    printf("after p=%p\n", p);
    print_array(&p, 10);

    //printf("-----------------------\n");
    //print_array2(p, 10);
}

void test2() {
    int *p = NULL;
    allocateSpace2(p);
    print_array2(p, 10);
}

void test3() {
    int a = 1;
    int *p = &a;
    printf("p=%p\n", p);
    printf("&p=%p\n", &p);
    //这样是不行的，传变量里的值，改变不了
    allocateSpace3(p);
    printf("after p =%p\n", p);
    print_array2(p, 10);
}

void test4() {
    int *p = NULL;

    allocateSpace(&p);
    printf("after p=%p\n", p);
    //print_array(&p, 10);

    //int (*temp)[2]=&p;
    int (*temp)[2] = p;
    printf("temp=%p\n", temp);
    printf(" *temp=%d\n", temp[0][0]);
    temp++;
    printf(" temp=%p\n", temp);
    printf(" *temp=%d\n", temp[0][0]);

}
void test5() {
    int *p = NULL;

    allocateSpace(&p);
    print_array(&p, 10);
    printf("-----------------------\n");
    freeArray(&p,10);
    printf("----------释放后-------------\n");
    print_array(&p, 10);
}

void test7() {
    int **ptr = NULL;
    int num = 4, size = 4, i, j;

    ptr = (int **) malloc(num * sizeof(int *));
//    ptr指向声明数组  元素 存放int*

    for (i = 0; i < num; ++i) {
        *(ptr + i) = (int *) malloc(size * sizeof(int));
        printf("addr   %p\n", ptr + i);
        for (j = 0; j < size; ++j)
            *(*(ptr + i) + j) = (i + 1) * j;
    }
    for (i = 0; i < num; ++i) {
        for (j = 0; j < size; ++j) {
            printf("before (%d, %d) -> %d\n", i, j, *(*(ptr + i) + j));
            printf("before (%d, %d) -> %p\n", i, j,(*(ptr + i) + j));
        }
        printf("\n");
    }
    //freeArray2(ptr, 4);
    freeArray3(ptr, 4);
    //free(ptr);
//    ptr = NULL;
//ptr 悬空指针
}

int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test7();
    return 0;
}

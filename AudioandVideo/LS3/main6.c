#include <stdio.h>
#include <malloc.h>
#define David  99//宏变量
void allocateSpace(int **addr){
    int *temp = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i) {
        temp[i] = 100 + i;
    }
     *addr = temp;
}

//敲   * 括号
void freeArray(int *pArray){
    if (*pArray != NULL) {
        free(*pArray);
        *pArray = NULL;
    }
}
int main() {
    int *p = NULL;
//实参 不能改变外面的变量
//c传指针地址  能够改变变量
    allocateSpace(&p);
    freeArray(&p);

    return 0;
}

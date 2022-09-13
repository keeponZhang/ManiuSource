#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int swap(int x,int y){
    printf("swap before x: %d  y:%d\n", x, y);
    int tmp = x;
    x = y;
    y = tmp;
    printf("swap after x: %d  y:%d\n",x, y);
}

//指针  int *  指针     x    地址   1   值  2  0x00055FF1
int swap1(int *x, int *y) {
    printf("swap1 before x: %d  y:%d\n", *x, *y);
    int tmp = *x;
    *x = *y;
    *y = tmp;
    printf("swap1 after x: %d  y:%d\n",*x, *y);
}
    int main() {
//    java  不能实现
        int x = 2;
        int y = 4;
        swap1(&x, &y);//0x00055FF1  0x00055FF2
        printf("x: %d y: %d\n", x, y);
    }

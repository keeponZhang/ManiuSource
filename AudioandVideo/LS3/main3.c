#include <stdio.h>
#include <malloc.h>
#define David  99//宏变量
#define ADD(x,y) ((x)+(y))

int *get_str(){
    int  str[4]  = {10,120,19,20}; //栈区
//    int  *str  =malloc(16); //栈区，
    return str;

}
int main() {
    int *arr = get_str();
    printf("----> arr 0x%x",  arr);
    printf("%d ", *arr);

    return 0;
}

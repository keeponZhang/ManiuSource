#include <stdio.h>


int main() {
    //上面的是高地址
    int a = 1;
    int b = 2;
    int c = 3;
    printf("a:%p\n",&a);
    printf("b:%p\n",&b);
    printf("c:%p\n",&c);
    return 0;
}

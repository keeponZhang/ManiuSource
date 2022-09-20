#include <stdio.h>

typedef int FUNC(int, int);

void  func(int a,int b){
    printf("%d %d\n",a,b);
}

int main() {
    FUNC *p2 = func;
    p2(10, 20);
//    p2 &p2 *p2
    (&func)(10, 20);
    (*func)(10, 20);
    (*p2)(30, 20);

//    函数   *p2=p2=
    return 0;
}




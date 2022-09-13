#include <stdio.h>

int main() {


//    数组
    char str[5]={'h','e','l','l','o','\0' };
//
//栈  1   堆 2  常量池  3  栈  \0
    char str1[5]="hello";
    char *str2 = "hello";
//    *str2 = "david";
    printf("str=%s\n", str);

    printf("str=%s\n", str);
    printf("str=%s\n", str1);
    printf("str=%s\n", str2);
    return 0;
}

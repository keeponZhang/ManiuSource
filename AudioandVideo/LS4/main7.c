#include <stdio.h>

#include <stdlib.h>
#include <string.h>
int main() {
   const char *message = "david";//不是5个，默认加个
   char charArray[] = {'H', 'e', 'l', 'l', 'o'};
   printf("%s\n", message);
   while (*message != '\0') {
       printf("%c\n ", *message++);
   }
    //这里打印为0
    printf("%d\n ", strlen(message));
//  函数改变变量    变量的地址
//  改变指针变量    指针的地址   二级指针
//  pn函数   函数地址
    return 0;
}




#include <stdio.h>
#include <malloc.h>

typedef    struct {
      int a;//unsigned  无符号  正数
    int b;
} Person1;
int main() {
    Person1 *person1 = malloc(sizeof(Person1));
    //这里不是初始为0
    printf("Hello, World! before  %d\n", person1->a );
    person1->a = 44;
    person1->b = 22;
    printf("Hello, World!  %d\n", person1->a );
    printf("Hello, World!  %d\n", person1->a );
    printf("Hello, World! %d\n", person1->b );
    return 0;


}

#include <stdio.h>


void testch() {
    //左值就是一个可被存储的单元，右值就是一个可被读取的数据。
    //左值必须是一个被明确了的内存存储单元，可以用来被赋值；右值必须是一个能被读出来的确确实实的值，这个值可以是数据，可以是指针，可以是结构，反正只要能被读出来的，都可以定义为右值。
    char ch = 'a';
    char *cp = &ch;


    //作为右值,右值引用的是地址里的内容
    //ch 作为右值（右值是一个可被读取的数据，把ch的值读出来，赋值给name）
    char name = ch;
    //ch 作为左值（左值是一个可被存储的单元，把‘b’存储到ch）
    ch = 'b';
    //---------ch---------------

    printf("cp=%p\n", cp);
    printf("&ch=%p\n", &ch);
    //右值
    char *name2 = &ch;
    char *name3 = cp;
    printf(" *name2=%c\n", *name2);
    printf(" *name3=%c\n", *name3);
}

void testcp() {
    char *cp = "b";
    //
    //---------cp--右值------------ clion
    printf(" ---------------cp-----------------\n", cp);
    //（右值可以是地址）
    char *cp1 = cp;

    printf(" cp=%p\n", cp);
    printf("cp1=%p\n", cp1);
    //左值（左值是一个可被存储的单元,cp设置null）
    cp = NULL;

    printf("after cp=%p\n", cp);
    printf("after cp1=%p\n", cp1);

    cp= cp1;
    printf(" ---------------&cp-----------------\n", cp1);
    //    ---------------&cp-----------------
    //（左值是一个可被存储的单元）
    //参数 相当于左值，取指向内容cp（个人觉得传参是右值,等于号前面的到时可以看做为左值）
    printf("&cp=%p\n", &cp);
    //    右值(右值是一个可被读取的数据,包括地址)
    char **cp2 = &cp;
    printf("cp2=%p\n", cp2);

    //---------------*cp-------------------
    printf(" ---------------*cp-----------------\n", cp2);

    // 这个是间接访问操作，也叫解引用指针
    printf("*cp= %c\n", *cp);
    //    右值
    char name = *cp;
    printf("name= %c\n", name);
    //左值
    //这里会崩溃
    //*cp = 'y';
    //printf("*cp= %c\n", *cp);

    //---------------------*cp+1
    printf(" ---------------*cp+1-----------------\n", cp2);
    //作为右值(*优先级高)
        char name3 = *cp+1;
        printf("name3=%c\n",name3);
        printf("*cp=%c\n",*cp);   //还是字符'a'
    //    //作为右值（野指针)
        char name4 = *(cp+1);
        printf("name4=%c\n",name4);
    //（野指针)
        int *p;
        printf("p=%p\n",p);

}


void testpi() {
    //---------------
    int *p; // 指针未初始化，此时 p 为野指针
    printf("p=0x%x\n", p);
    int *pi = NULL;// 指针未初始化，此时 p 为空指针

    {
        int i = 6;
        printf("&i---%p\n  ", &i);
        pi = &i; // 此时 pi 指向一个正常的地址
        *pi = 8; // ok
        printf("代码块pi---%p\n ", pi);
    }
// 由于 pi 指向的变量 i 已经销毁，此时 pi 即成了悬空指针
    int b = *pi;// i
    printf("b---%d\n", b);
    printf("pi---%p", pi);
}

int main() {
    //testch();
    //testcp();
    testpi();








    return 0;
/**
* ch
&ch
cp
&cp
*cp
*cp+1
*(cp+1)
++cp
cp++
*++cp
*cp++
++*cp
(*cp)++
++*++cp
++*cp++
 */
//    int *p = NULL;
//     *p = 0;
    return 0;
}

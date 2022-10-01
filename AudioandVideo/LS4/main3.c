#include <stdio.h>


void  func(int a,int b){
    printf("%d %d\n",a,b);
}
//func  虚拟机 中
//view.setOnclickListentrt()
//FFmpeg
int call(int result){
    printf("------->%d\n", result);
}
//解码类----》回调给视频渲染类
int test(int a,int b,int (*callback)(int)){
    int reslut = a + b;
    callback(reslut);

}
void test2() {
    printf("---------test2---------------\n");
    func(20, 10);
    //    func  &func  *func
    printf("func =%p\n", func);
    printf("&func =%p\n", &func);
    printf("*func =%p\n", *func);

//指向类型没有意义，因为指向的是代码区域
}
void test3() {
    printf("---------test3---------------\n");
    func(20, 10);
    //函数指针
    void (*p)(int, int);
    p(10, 20);
}
void test4() {
    printf("---------test4---------------\n");
    func(30, 10);
    //函数指针
    void (*p)(int, int);
    p = func;
    p(10, 20);

}
void test5() {
    printf("---------test5---------------\n");
    test(30, 40, call);
}
void test6() {
    printf("---------test6---------------\n");
}
void test7() {
    printf("---------test7---------------\n");
}


int main() {
    test2();
    //test3();
    //test4();
    test5();
    test6();
    test7();
    return 0;
}

void testOriginal() {


}


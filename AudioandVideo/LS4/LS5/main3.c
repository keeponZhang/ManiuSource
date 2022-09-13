#include <stdio.h>


void  func(int a,int b){
    printf("%d %d\n",a,b);
}
//func  虚拟机 中
//view.setOnclickListentrt()
//FFmpeg

//解码类----》回调给视频渲染类
int test(int a,int b,int (*callback)(int)){

    int reslut = a + b;
    callback(reslut);

}
int call(int result){
    printf("------->%d", result);
}
int main() {
    func(20, 10);
//    func  &func  *func
    printf("func =%p\n", func);
    printf("&func =%p\n", &func);
    printf("*func =%p\n", *func);
//指向类型 没有 代码区域
//java  指针

    void (*p)(int, int);
    p = func;
    p(10, 20);
    test(30, 40, call);
    return 0;
}




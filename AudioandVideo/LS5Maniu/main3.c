#include <stdio.h>

int main() {
//javabean  声明 内部类
    struct Person {
        char  name;  //姓名 1
        int num;  //学号 4
        int age;  //年龄 4
        char group;  //所在学习小组 1
        float score;  //成绩  4
    } person1,person2;
    printf(" person1 %d ", sizeof(float));
    printf(" person1 %d ", sizeof(person1));
    return 0;
}

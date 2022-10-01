#include <iostream>

struct Student{
    //结构体包含的成员变量
    char *name;
    int age;
    float score;
};

void display(struct Student stu){
    printf("name %s age %d score %f\n", stu.name, stu.age, stu.score);
}
int main() {

    struct Student stu1;
    //为结构体的成员变量赋值
    stu1.name = "xiaoming";
    stu1.age = 15;
    stu1.score = 92.5;
    //调用函数
    display(stu1);

    return 0;
}
